#pragma once
#include <objbase.h>
#include "OS11_HTAPI.h"

#define FNAME L"Kravtsova14.CA.COM"
#define VINDX L"Kravtsova14.CA.1"
#define PRGID L"Kravtsova14.CA"



// {6BFAC9E4-BC7D-4C72-B0F0-19DDA5918555}
static const GUID CLSID_CA =
{ 0x6bfac9e4, 0xbc7d, 0x4c72, { 0xb0, 0xf0, 0x19, 0xdd, 0xa5, 0x91, 0x85, 0x55 } };

// {53823632-866A-49F8-B7DF-AF44A242B0C1}
static const GUID IID_IOS13  =
{ 0x53823632, 0x866a, 0x49f8, { 0xb7, 0xdf, 0xaf, 0x44, 0xa2, 0x42, 0xb0, 0xc1 } };


interface IOS13 :IUnknown {
    STDMETHOD(Add(const double, const double, double*)) PURE;
    
	STDMETHOD(Sub(const double, const double, double*)) PURE;

	STDMETHOD(Create   //  создать HT             
	(
		int	  Capacity,					   // емкость хранилища
		int   SecSnapshotInterval,		   // переодичность сохранения в сек.
		int   MaxKeyLength,                // максимальный размер ключа
		int   MaxPayloadLength,            // максимальный размер данных
		const wchar_t  FileName[512],          // имя файла 
		const wchar_t  HTUsersGroup[512],          // имя файла 
		HT::HTHANDLE** result
	)) PURE; 	// != NULL успешное завершение  

	STDMETHOD(Open     //  открыть HT             
	(
		const wchar_t    FileName[512],         // имя файла 
		HT::HTHANDLE** result
	)) PURE; 	// != NULL успешное завершение 

	STDMETHOD(Open     //  открыть HT             
	(
		const wchar_t    FileName[512],         // имя файла 
		const wchar_t    userName[512],         // имя файла 
		const wchar_t    password[512],         // имя файла 
		HT::HTHANDLE** result
	)) PURE; 	// != NULL успешное завершение  

	STDMETHOD(Close     //  открыть HT             
	(
		HT::HTHANDLE** hthandle           // управление HT (File, FileMapping)
	)) PURE; 	// != NULL успешное завершение 

	STDMETHOD(OpenExist     //  открыть HT             
	(
		const wchar_t    FileName[512],         // имя файла 
		HT::HTHANDLE** result
	)) PURE; 	// != NULL успешное завершение 

	STDMETHOD(Snap     //  открыть HT             
	(
		HT::HTHANDLE** hthandle
	)) PURE; 	// != NULL успешное завершение 

	STDMETHOD(Insert     //  открыть HT             
	(
		HT::HTHANDLE** hthandle,            // управление HT
		HT::Element** element              // элемент
	)) PURE; 	// != NULL успешное завершение

	STDMETHOD(Get     //  открыть HT             
	(
		HT::Element** result,
		HT::HTHANDLE** hthandle,            // управление HT
		HT::Element** element              // элемент 
	)) PURE; 	// != NULL успешное завершение

	STDMETHOD(Delete     //  открыть HT             
	(
		HT::HTHANDLE** hthandle,            // управление HT (ключ)
		HT::Element** element              // элемент 
	)) PURE; 	// != NULL успешное завершение

	STDMETHOD(Update     //  открыть HT             
	(
		HT::HTHANDLE** hthandle,            // управление HT
		HT::Element** oldelement,          // старый элемент (ключ, размер ключа)
		void** newpayload,          // новые данные  
		int*   newpayloadlength     // размер новых данных
	)) PURE; 	// != NULL успешное завершение

	STDMETHOD(GetLastErrorProg     //  открыть HT             
	(
		std::string& error,
		HT::HTHANDLE** ht                         // управление HT
	)) PURE; 	// != NULL успешное завершение

	STDMETHOD(CreateElement     //  открыть HT             
	(
		std::string* key,
		HT::Element** el                         // управление HT
	)) PURE; 	// != NULL успешное завершение

	STDMETHOD(CreateElement     //  открыть HT             
	(
		std::string* key,
		std::string* payload,
		HT::Element** el                         // управление HT
	)) PURE; 	// != NULL успешное завершение

	STDMETHOD(print     //  открыть HT             
	(
		HT::Element** element              // элемент 
	)) PURE; 	// != NULL успешное завершение
};

