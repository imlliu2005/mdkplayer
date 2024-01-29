# ffmpeg_rtsp
### 生成编译文件：
- cmake ../ -G Ninja -DCMAKE_BUILD_TYPE=Release
- cmake ../ -G Ninja -DCMAKE_BUILD_TYPE=Debug

### 检查内存
```
#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__) // 定义new宏来替换new关键字
#endif
```

### main 函数添加
```
#ifdef _MSC_VER
    // _CrtSetBreakAlloc(590);
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
#ifdef MEMORY_STDOUT // 是否将内存泄露信息，存储到文件中
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
#else
    HANDLE hLogFile;
    hLogFile = CreateFile("./memory.txt", GENERIC_WRITE,
                          FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL, NULL);
    _CrtSetReportFile(_CRT_WARN, hLogFile);
    _CrtSetReportFile(_CRT_ERROR, hLogFile);
    _CrtSetReportFile(_CRT_ASSERT, hLogFile);
#endif // MEMORY_STDOUT
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

#endif // _MSC_VER
```

### 格式化输出
- qSetMessagePattern("[%{time yyyy-MM-dd hh:mm:ss.zzz}] %{file} %{line} %{function} %{message}");

### c++ include config
- C:/Qt/Qt5.14.2/5.14.2/msvc2017_64/include
- C:/Qt/Qt5.14.2/5.14.2/msvc2017_64/include/QtCore
- C:/Qt/Qt5.14.2/5.14.2/msvc2017_64/include/QtWidgets