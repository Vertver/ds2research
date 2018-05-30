#include <windows.h>

#define DS2BASE_API __declspec(dllimport) 

struct IFileSystem
{
	void* pFileSystem;
	DWORD dwUnknown;
	void* pUnknown;
	DWORD dwUnknown2;
};

DS2BASE_API class IExpressionEvaluator
{
public:
	IExpressionEvaluator(IExpressionEvaluator const &);
	IExpressionEvaluator(void);
	virtual ~IExpressionEvaluator(void);
	void* operator=(IExpressionEvaluator const &);
};

extern "C"
{
	DS2BASE_API void* CreateConfigFile();
	DS2BASE_API IFileSystem* GetFileSystem();
	DS2BASE_API void* GetGDFRegistry();
	DS2BASE_API void* IsNumber(void*);
	DS2BASE_API void* ReadConfigFile(void*, void*, void*);
	DS2BASE_API void* Str_GetFileExtension(void*);
	DS2BASE_API void* Str_GetFileName(void*);
	DS2BASE_API void* Str_GetPath(void*, void*);
	DS2BASE_API void* TGAwrite();
}

DS2BASE_API class IDataReader* __cdecl ReadFile(int, char const *, int);
DS2BASE_API class IDataWriter* __cdecl WriteFile(int, char const *, int);

class CCachedFileReader
{
protected: 
	static DS2BASE_API void __cdecl cache_create(void**, DWORD*);
	static DS2BASE_API void __cdecl cache_release(void*);
};

DS2BASE_API void* g_data_container;
DS2BASE_API void* g_str_container;

DS2BASE_API class IConfigFile* __cdecl get_engine_cfg(void);
DS2BASE_API BOOL __stdcall ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped);
DS2BASE_API BOOL __stdcall WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);