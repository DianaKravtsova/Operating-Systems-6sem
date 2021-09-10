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

	STDMETHOD(Create   //  ������� HT             
	(
		int	  Capacity,					   // ������� ���������
		int   SecSnapshotInterval,		   // ������������� ���������� � ���.
		int   MaxKeyLength,                // ������������ ������ �����
		int   MaxPayloadLength,            // ������������ ������ ������
		const wchar_t  FileName[512],          // ��� ����� 
		const wchar_t  HTUsersGroup[512],          // ��� ����� 
		HT::HTHANDLE** result
	)) PURE; 	// != NULL �������� ����������  

	STDMETHOD(Open     //  ������� HT             
	(
		const wchar_t    FileName[512],         // ��� ����� 
		HT::HTHANDLE** result
	)) PURE; 	// != NULL �������� ���������� 

	STDMETHOD(Open     //  ������� HT             
	(
		const wchar_t    FileName[512],         // ��� ����� 
		const wchar_t    userName[512],         // ��� ����� 
		const wchar_t    password[512],         // ��� ����� 
		HT::HTHANDLE** result
	)) PURE; 	// != NULL �������� ����������  

	STDMETHOD(Close     //  ������� HT             
	(
		HT::HTHANDLE** hthandle           // ���������� HT (File, FileMapping)
	)) PURE; 	// != NULL �������� ���������� 

	STDMETHOD(OpenExist     //  ������� HT             
	(
		const wchar_t    FileName[512],         // ��� ����� 
		HT::HTHANDLE** result
	)) PURE; 	// != NULL �������� ���������� 

	STDMETHOD(Snap     //  ������� HT             
	(
		HT::HTHANDLE** hthandle
	)) PURE; 	// != NULL �������� ���������� 

	STDMETHOD(Insert     //  ������� HT             
	(
		HT::HTHANDLE** hthandle,            // ���������� HT
		HT::Element** element              // �������
	)) PURE; 	// != NULL �������� ����������

	STDMETHOD(Get     //  ������� HT             
	(
		HT::Element** result,
		HT::HTHANDLE** hthandle,            // ���������� HT
		HT::Element** element              // ������� 
	)) PURE; 	// != NULL �������� ����������

	STDMETHOD(Delete     //  ������� HT             
	(
		HT::HTHANDLE** hthandle,            // ���������� HT (����)
		HT::Element** element              // ������� 
	)) PURE; 	// != NULL �������� ����������

	STDMETHOD(Update     //  ������� HT             
	(
		HT::HTHANDLE** hthandle,            // ���������� HT
		HT::Element** oldelement,          // ������ ������� (����, ������ �����)
		void** newpayload,          // ����� ������  
		int*   newpayloadlength     // ������ ����� ������
	)) PURE; 	// != NULL �������� ����������

	STDMETHOD(GetLastErrorProg     //  ������� HT             
	(
		std::string& error,
		HT::HTHANDLE** ht                         // ���������� HT
	)) PURE; 	// != NULL �������� ����������

	STDMETHOD(CreateElement     //  ������� HT             
	(
		std::string* key,
		HT::Element** el                         // ���������� HT
	)) PURE; 	// != NULL �������� ����������

	STDMETHOD(CreateElement     //  ������� HT             
	(
		std::string* key,
		std::string* payload,
		HT::Element** el                         // ���������� HT
	)) PURE; 	// != NULL �������� ����������

	STDMETHOD(print     //  ������� HT             
	(
		HT::Element** element              // ������� 
	)) PURE; 	// != NULL �������� ����������
};

