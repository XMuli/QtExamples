# Windows 效能模式

如何在 C++ 和 WebView 里面开启 效能模式，降低程序的功耗。 其支持平台 Win11 22H2。 原理和介绍参见如下

- [Windows 11 效率模式简介及使用](https://www.sysgeek.cn/windows-11-efficiency-mode/)
- [什么是Win11效率模式及如何使用它](https://win.bandwh.com/opti/683.html)



**编译环境:** Win11 24H2  VS2022



## MyWindowsEfficiencyMode （C++）

- C++ windows 版本代码，添加如下代码，然后运行  EnableEfficiencyModeForCurrentProcess() 函数

```cpp
#include <windows.h>
#include <iostream>

// 开启 Efficiency Mode 的函数
void EnableEfficiencyModeForCurrentProcess()
{
    HANDLE hProcess = GetCurrentProcess();

    // 1. 降低调度优先级至 Idle
    SetPriorityClass(hProcess, IDLE_PRIORITY_CLASS);

    // 2. 启用 EcoQoS 节能模式
    PROCESS_POWER_THROTTLING_STATE pts = {};
    pts.Version = PROCESS_POWER_THROTTLING_CURRENT_VERSION;
    pts.ControlMask = PROCESS_POWER_THROTTLING_EXECUTION_SPEED;
    pts.StateMask = PROCESS_POWER_THROTTLING_EXECUTION_SPEED;

    if (!SetProcessInformation(
        hProcess,
        ProcessPowerThrottling,
        &pts,
        sizeof(pts)))
    {
        DWORD err = GetLastError();
        std::cerr << "开启 EcoQoS 失败，错误码：" << err << "\n";
    }
    else {
        std::cout << "效率模式已启用\n";
    }
}
```

![image-20250710175353052](./assets/image-20250710175353052.png)



**运行效果**

![image-20250710175138418](./assets/image-20250710175138418.png)





## WebView2 (微软自带库)

`int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)`

里面调用  EnableEfficiencyModeForCurrentProcess() 函数可以开启 C++ windows 窗口开启效能模式





**WebView** 

对于上面窗口里面嵌套 WebView 窗口，由于 WebView  是独立的，需要单独任务管理器中搜索；

webview 加载的代码附近如下

```cpp
	ComPtr<ICoreWebView2Environment3> webViewEnvironment3;
	m_webViewEnv->QueryInterface(IID_PPV_ARGS(&webViewEnvironment3));
	HRESULT hr = webViewEnvironment3->CreateCoreWebView2CompositionController(m_hMainWnd, Callback<ICoreWebView2CreateCoreWebView2CompositionControllerCompletedHandler>(
		this, &AppWindow::xxxxfunction).Get());
```

在 附近的 `xxxxfunction` 函数里面去添加如下代码

```cpp
// 启用 WebView2 子进程的效率模式（EcoQoS）
UINT32 pid = 0;
if (SUCCEEDED(g_webView->get_BrowserProcessId(&pid)) && pid != 0) {
    HANDLE hProcess = OpenProcess(PROCESS_SET_INFORMATION | PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
    if (hProcess) {
        SetPriorityClass(hProcess, IDLE_PRIORITY_CLASS);

        PROCESS_POWER_THROTTLING_STATE pts = {};
        pts.Version = PROCESS_POWER_THROTTLING_CURRENT_VERSION;
        pts.ControlMask = PROCESS_POWER_THROTTLING_EXECUTION_SPEED;
        pts.StateMask = PROCESS_POWER_THROTTLING_EXECUTION_SPEED;
        SetProcessInformation(hProcess, ProcessPowerThrottling, &pts, sizeof(pts));
        CloseHandle(hProcess);
    }
}
```



开启成功截图

![image-20250710180417278](./assets/image-20250710180417278.png)



---

## WebView2 开启参数，降低资源占用方式

```cpp
// 推荐的 WebView2 启动参数配置（分类注释说明）
// 微软参数文档：https://learn.microsoft.com/en-us/microsoft-edge/webview2/concepts/webview-features-flags?tabs=dotnetcsharp
// Chrome 文档：https://peter.sh/experiments/chromium-command-line-switches/
// 跟踪实际行为：启动 WebView2 时加上 --enable-logging=stderr --v=1，可以监控是否参数生效。

var arguments = string.Join(" ", new[]
{
    "--disable-gpu",	                                                             // ✅ 推荐	     降低 GPU 活动，节省功耗（尤其适合静态页面）	    会影响 WebGL、Canvas 渲染性能，某些页面可能变卡
    "--disable-site-isolation-trials",	                                             // ✅ 推荐	     减少多进程分离带来的资源开销	                    安全隔离性略下降，影响不大
    "--disable-shared-workers",	                                                     // ✅ 推荐	     避免 Web Worker 常驻线程消耗	                    某些应用如 WebIM、后台通信可能会失败
    //"--disable-renderer-backgrounding",	                                     // ⚠️ 按需	     禁用后台渲染降优先级，保持活跃响应	                会持续占用资源和电量，适用于需要后台实时更新的场景
    //"--disable-features=AudioServiceOutOfProcess,IsolateOrigins,site-per-process", // ⚠️ 谨慎使用	 减少子进程，提高整合度；可能降功耗	                降低安全性、影响复杂页面兼容性
    //"--disable-dev-shm-usage",	                                             // ⚠️ 一般不推荐	 用于共享内存不可靠的环境（如容器）	                桌面环境一般无影响，禁用可能反而增加内存开销
    //"--disable-software-rasterizer",	                                             // ❌ 不推荐	     若 GPU 被禁用，此项关闭会导致无法回退至 CPU 渲染	页面会显示异常甚至渲染失败（白屏）
    //"--disable-backgrounding-occluded-windows",	                             // ❌ 不推荐	     正常被遮挡的窗口应当节能处理	                    阻止系统节电优化，增加整体功耗
  });

var options = new CoreWebView2EnvironmentOptions
{
    AdditionalBrowserArguments = arguments
};

var env = await CoreWebView2Environment.CreateAsync(null, userDataFolder, options);
await webView.EnsureCoreWebView2Async(env);
```
