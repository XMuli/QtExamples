#ifndef EXDEFINEGLOBAL_H
#define EXDEFINEGLOBAL_H

//用来定义一些宏的使用: 尝试写大项目的架构

//定义命名空间的宏(在定义 class ExCustomStyle:  的时候用到了  eg: ExCustomStyle.h  ExCustomStyle.cpp里面)
#define CUSTOMSTYLE_BEDGIN_NAMESPACE namespace touwoyimuliStyle {
#define CUSTOMSTYLE_END_NAMESPACE }

#define CUSTOM_BEGIN_NAMESPACE namespace touwoyimuliDrawUtils {          //嵌套于命名空间 touwoyimuliDrawUtils里面
#define CUSTOM_END_NAMESPACE }

//定义使用命名空间((在使用 class ExCustomStyle的定义内容时候用到了  eg:Examples.cpp里面))
#define CUSTOMSTYLE_USE_NAMESPACE using namespace touwoyimuliStyle;



#endif // EXDEFINEGLOBAL_H
