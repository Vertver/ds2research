#define ENGINE_API __declspec(dllexport)

class CDS2Engine
{
public:

};

/*
class ENGINE_API IDS2Engine
{
public:
	void __cdecl GetDS2Engine(void);
};
*/

//__declspec(dllexport) class IDS2Engine* __cdecl GetDS2Engine(void);

__declspec(dllexport) class ENGINE_API IDS2Engine
{
	__cdecl GetDS2Engine(void);
};
