---
title: WINDOWS/MSVC 所遇到奇葩问题集锦
date: 2023-05-01 12:22:28
updated: 2023-06-01 15:15:28
---



# WINDOWS 所遇到奇葩问题集锦



[toc]

## NT/MSVC 编译开发问题

1. 如何设置安装 Visual Studio Install 使用英文语言运行？ 

   [解] 程序运行后添加 ` --locale en-US` 即可

2. `QString` 转 `char *` 莫名其妙会失败？！！！

   <details>
       <summary> [解] 转换分为两步来完成一定没有问题，但是一步直接到， MSVC 下会偶尔有问题 </summary>
     <p> 在 https://github.com/feiyangqingyun/qtkaifajingyan 的 185 条已总结，同遇到和排查出来，真滴是血的教训，操操操 </p>
     <pre>
     QString text = "xxxxx";
     //下面这样转换很可能会有问题
     char *data = text.toUtf8().data();
     //分两步转换肯定不会有问题
     QByteArray buffer = text.toUtf8();
     char *data = buffer.data();
     const char *data = buffer.constData();
     </pre>
   </details>

3. 微软 SDK 导致的项目编译失败哦~                                                                                                                    [[解]](https://blog.csdn.net/qq_33154343/article/details/124736720)

4. Win10的20H2使用VS2019，拖曳窗口会崩溃！！！                                                                                      [[解]](https://blog.csdn.net/qq_33154343/article/details/116244656)

5. VS2019调试Qt5时QString显示为内存地址而非字符串！！！                                                                       [[解]](https://xmuli.blog.csdn.net/article/details/116244865)

6. 一个微软自带的 Notepad 所导致的问题，回车符（CR）和换行符（LF）。                                               [[解]](https://blog.csdn.net/qq_33154343/article/details/123508220)

7. Visual Studio 断点调试之箭头偏移进错函数，捉虫记                                                                                    [[解]](https://blog.csdn.net/qq_33154343/article/details/124482152)

8. Qt Creator(Qt 15.2) 使用 MinGW 则会编译成功，改用 MSVC 2022 却编译失败！！！

   <details>
       <summary> [解] 某些中文注释会导致编译失败 （操！！！） </summary>
     <p> MSVC 的 .h.cpp 都采用 UTF8-BOM 格式， </p>
     <pre><img src="https://fastly.jsdelivr.net/gh/XMuli/xmuliPic@pic/2023/%E4%B8%8D%E5%8F%AF%E5%88%A0%E9%99%A4Snipaste_2023-05-13_21-04-59.png" width="100%"/>
     </pre>
   </details>

9. Qt Creator(Qt 15.2) 使用 MinGW 终端的中文不会乱码，改用 MSVC 2022 却中文乱码

   <details>
       <summary> [解] 某些中文注释会导致编译失败 （操！！！），CMake 中设置 utf-8 </summary>
     <p> MSVC 的 .h.cpp 都采用 UTF8-BOM 格式。同时可参考 8 条 </p>
     <pre>
     # 采用 MSVC 终端上的中文不乱码
   if (MSVC)
       set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
       add_compile_options(/source-charset:utf-8 /execution-charset:utf-8) // 根据实际可注释
   endif()
     </pre>
   </details>

10. Qt 5.15 获取音频的输入输出，使用 MinGW 则会编译仅仅会获取一份，改用 MSVC 2022 却编译却会获得信息重复

    <details>
        <summary> [解] 详细参数确实有不同，如何去重的方法还在寻找中。 已解决，手动写了一个算法进行去重。 </summary>
      <p> MSVC 和 MinGW 的又一个不相同，哔了狗 </p>
      <pre>
      【问题源码和打印显示】
        // 获取音频输入设备列表
        QList<QAudioDeviceInfo> inputDevices = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
        qDebug() << "音频输入设备列表：";
        for (const QAudioDeviceInfo& deviceInfo : inputDevices) {
            qDebug() << "设备名称：" << deviceInfo.deviceName();
    		qDebug() << "支持的采样率：" << deviceInfo.supportedSampleRates();
    		qDebug() << "支持的声道数：" << deviceInfo.supportedChannelCounts();
    		qDebug() << "支持的采样大小：" << deviceInfo.supportedSampleSizes();
    		qDebug() << "支持的编码格式：" << deviceInfo.supportedCodecs();
    		qDebug() << "-------------------------------------";
        }
        // 获取音频输出设备列表
        QList<QAudioDeviceInfo> outputDevices = QAudioDeviceInfo::availableDevices(QAudio::AudioOutput);
        qDebug() << "音频输出设备列表：";
        for (const QAudioDeviceInfo& deviceInfo : outputDevices) {
            qDebug() << "设备名称：" << deviceInfo.deviceName();
    		qDebug() << "支持的采样率：" << deviceInfo.supportedSampleRates();
    		qDebug() << "支持的声道数：" << deviceInfo.supportedChannelCounts();
    		qDebug() << "支持的采样大小：" << deviceInfo.supportedSampleSizes();
    		qDebug() << "支持的编码格式：" << deviceInfo.supportedCodecs();
    		qDebug() << "-------------------------------------";
        }
    🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣
    ***********************************MSVC 编译器输出***********************************
    [debug]  m_microphoneDevices设备名称： "麦克风阵列 (适用于数字麦克风的英特尔? 智音技术)"
    [debug] 支持的采样率： (8000, 11025, 16000, 22050, 32000, 44100, 48000, 88200, 96000, 192000)
    [debug] 支持的声道数： (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18)
    [debug] 支持的采样大小： (8, 16, 24, 32, 48, 64)
    [debug] 支持的编码格式： ("audio/pcm")
    [debug] -------------------------------------
    [debug]  m_microphoneDevices设备名称： "麦克风阵列 (适用于数字麦克风的英特尔? 智音技术)"
    [debug] 支持的采样率： ()
    [debug] 支持的声道数： (1, 2)
    [debug] 支持的采样大小： ()
    [debug] 支持的编码格式： ("audio/pcm")
    [debug] -------------------------------------
    [debug] m_speakerDevices 设备名称： "扬声器 (Realtek(R) Audio)"
    [debug] 支持的采样率： (8000, 11025, 16000, 22050, 32000, 44100, 48000, 88200, 96000, 192000)
    [debug] 支持的声道数： (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18)
    [debug] 支持的采样大小： (8, 16, 24, 32, 48, 64)
    [debug] 支持的编码格式： ("audio/pcm")
    [debug] -------------------------------------
    [debug] m_speakerDevices 设备名称： "P27q-30 (NVIDIA High Definition Audio)"
    [debug] 支持的采样率： (8000, 11025, 16000, 22050, 32000, 44100, 48000, 88200, 96000, 192000)
    [debug] 支持的声道数： (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18)
    [debug] 支持的采样大小： (8, 16, 24, 32, 48, 64)
    [debug] 支持的编码格式： ("audio/pcm")
    [debug] -------------------------------------
    [debug] m_speakerDevices 设备名称： "P27q-30 (NVIDIA High Definition Audio)"
    [debug] 支持的采样率： (48000)
    [debug] 支持的声道数： (2)
    [debug] 支持的采样大小： (8, 16, 24, 32, 64)
    [debug] 支持的编码格式： ("audio/pcm")
    [debug] -------------------------------------
    [debug] m_speakerDevices 设备名称： "扬声器 (Realtek(R) Audio)"
    [debug] 支持的采样率： (48000)
    [debug] 支持的声道数： (2)
    [debug] 支持的采样大小： (8, 16, 24, 32, 64)
    [debug] 支持的编码格式： ("audio/pcm")
    [debug] -------------------------------------
    🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣
    ***********************************MinGW 编译器输出***********************************
    [debug]  m_microphoneDevices设备名称： "麦克风阵列 (适用于数字麦克风的英特尔? 智音技术)"
    [debug] 支持的采样率： (8000, 11025, 16000, 22050, 32000, 44100, 48000, 88200, 96000, 192000)
    [debug] 支持的声道数： (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18)
    [debug] 支持的采样大小： (8, 16, 24, 32, 48, 64)
    [debug] 支持的编码格式： ("audio/pcm")
    [debug] -------------------------------------
    [debug] m_speakerDevices 设备名称： "扬声器 (Realtek(R) Audio)"
    [debug] 支持的采样率： (8000, 11025, 16000, 22050, 32000, 44100, 48000, 88200, 96000, 192000)
    [debug] 支持的声道数： (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18)
    [debug] 支持的采样大小： (8, 16, 24, 32, 48, 64)
    [debug] 支持的编码格式： ("audio/pcm")
    [debug] -------------------------------------
    [debug] m_speakerDevices 设备名称： "P27q-30 (NVIDIA High Definition Audio)"
    [debug] 支持的采样率： (8000, 11025, 16000, 22050, 32000, 44100, 48000, 88200, 96000, 192000)
    [debug] 支持的声道数： (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18)
    [debug] 支持的采样大小： (8, 16, 24, 32, 48, 64)
    [debug] 支持的编码格式： ("audio/pcm")
    [debug] -------------------------------------
    🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣
    【解决方案】还在找中，或者看如何去重
    </pre>
    </details>

11. xxx

    

<br>

## WINDOWS 问题

1. Teams 始终无法登录，提示如图：我们无法连接到你。 HTTP 404  login.micsoftonline.com

   <details>
       <summary> [解] Teams 安装应用程序-属性-运行兼容性疑难解答 </summary>
     <p> [含详细报错图片 和 解决图] </p>
     <pre><img src="https://fastly.jsdelivr.net/gh/XMuli/xmuliPic@pic/2023/Snipaste_2023-05-15_11-05-48.png" width="50%"/>解决方案：<img src="https://fastly.jsdelivr.net/gh/XMuli/xmuliPic@pic/2023/20230515161422.png" width="50%"/>
     </pre>
   </details>

2. Office 365 企业版，无法登录账号

   [解] 关掉系统代理（代理直连也不行，必须要关掉），[ref1 评论](https://zhuanlan.zhihu.com/p/392977620)

3. 重装系统后，自动更新后，托盘的喇叭🔈图标错误，且无法打开

   <details>
       <summary> [解] 运行命令如下，亲测可用 </summary>
     <p> 参考 https://blog.csdn.net/Bigotry_1/article/details/121957884 </p>
     <pre> 
   1.首先按下“win+R”打开运行的窗口，点击输入命令“cmd”，并以管理员身份进入
   2.然后在弹出来的窗口中点击输入“DISM.exe /Online /Cleanup-image /Scanhealth”，回车确定扫描映像是否完整
   3.然后完成后再检测映像，输入：DISM.exe /Online /Cleanup-image /Checkhealth。
   4.然后再修复映像，输入：DISM.exe /Online /Cleanup-image /Restorehealth。
   5.最后检查系统并修复：sfc /scannow。
   6.重启电脑，然后就完成了
     </pre>
   </details>



## QtCreator 问题

1. 使用 Qt Creator 提升控件自定义控件时，操作如下， MSVC 和 WinGW 都可编译通过，亲测出来的方案；通常报错如下

   ```bash
   通常报错 ”ui_mainui.h:22:10: fatal error: chatinputedit.h: No such file or directory
    #include "chatinputedit.h"
             ^~~~~~~~~~~~~~~~~“
   ```

   

   1. `promoted to` 提升自定控件操作如图，然后在 CMakeLists.txt  中添加包含此头文件的路径，添加 `include_directories(${PROJECT_SOURCE_DIR}/widgets)`，用于修复 Qt Design 使用提升自定义控件后， MinGW 找不到而编译失败。

      <img src="https://fastly.jsdelivr.net/gh/XMuli/xmuliPic@pic/2023/20230619010003.png" width="100%"/>

   - 若是要降低会原本的 Q控件，使用 `Demote to`

   - 若仅仅只用 MSVC 编译，上图片中的 `Promoted class name:` 添加自定义类名后，在 `Header file:` 后面自动生成文件后，补上其相对路径的部分，然后 不用写 include_directories 这一行，也可以直接编译通过



MacOS & Clang64
编译 Qt+CMake 报错：`:-1: error: ninja: build stopped: subcommand failed.`
原因： 1.可能得 kit 没有设置好 2. CMake 没有安装好 3. CMakeList.txt 里面的语法存在错误，屏蔽排查





<br>

## GITHUB 问题

1. GitHub 的 Action 的脚本，构建 CI/CD，使用的默认 shell 壳： pwd 默认是不使用 utf8 字符

   <details>
       <summary> [解] 使用的默认 shell 壳： pwd 默认是不使用 utf8 字符 </summary>
     <p> 使用的命令参数  </p>
     <pre>
   ${{ env.xxxx }}
   ${{env.xxxx}}
   ${{env:xxxx}}
   ${env.xxxx}
   $xxxx
   然后参数要注意；使用 ""  或者 ''
   学会去看一些公共的库；直接去看最新的文档之类
   </pre>
   </details>

2. xxx
