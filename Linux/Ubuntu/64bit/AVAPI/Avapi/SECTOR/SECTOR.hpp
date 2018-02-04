#ifndef SECTOR_HPP_INCLUDED
#define SECTOR_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

class MetaData_Type_SECTOR
{
private:
    string Information;
    string LastRefreshed;

public:
    MetaData_Type_SECTOR();
    MetaData_Type_SECTOR(const MetaData_Type_SECTOR& other); // copy constructor
    string get_Information() const {return Information;};
    string get_LastRefreshed() const {return LastRefreshed;};
    void set_Information(string Information){this->Information = Information;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class RankA_Type_SECTOR
{
private:
    string RankName;
    string Financials;
    string Utilities;
    string HealthCare;
    string Industrials;
    string RealEstate;
    string Materials;
    string TelecommunicationServices;
    string ConsumerDiscretionary;
    string ConsumerStaples;
    string InformationTechnology;
    string Energy;

public:
    RankA_Type_SECTOR();
    RankA_Type_SECTOR(const RankA_Type_SECTOR& other); // copy constructor

    string get_RankName() const {return RankName;};
    string get_Financials() const {return Financials;};
    string get_Utilities() const {return Utilities;};
    string get_HealthCare() const {return HealthCare;};
    string get_Industrials() const {return Industrials;};
    string get_RealEstate() const {return RealEstate;};
    string get_Materials() const {return Materials;};
    string get_TelecommunicationServices() const {return TelecommunicationServices;};
    string get_ConsumerDiscretionary() const {return ConsumerDiscretionary;};
    string get_ConsumerStaples() const {return ConsumerStaples;};
    string get_InformationTechnology() const {return InformationTechnology;};
    string get_Energy() const {return Energy;};
    void set_RankName(string RankName){this->RankName = RankName;};
    void set_Financials(string Financials){this->Financials = Financials;};
    void set_Utilities(string Utilities){this->Utilities = Utilities;};
    void set_HealthCare(string HealthCare){this->HealthCare = HealthCare;};
    void set_Industrials(string Industrials){this->Industrials = Industrials;};
    void set_RealEstate(string RealEstate){this->RealEstate = RealEstate;};
    void set_Materials(string Materials){this->Materials = Materials;};
    void set_TelecommunicationServices(string TelecommunicationServices){this->TelecommunicationServices = TelecommunicationServices;};
    void set_ConsumerDiscretionary(string ConsumerDiscretionary){this->ConsumerDiscretionary = ConsumerDiscretionary;};
    void set_ConsumerStaples(string ConsumerStaples){this->ConsumerStaples = ConsumerStaples;};
    void set_InformationTechnology(string InformationTechnology){this->InformationTechnology = InformationTechnology;};
    void set_Energy(string Energy){this->Energy = Energy;};

    int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class RankB_Type_SECTOR
{
private:
    string RankName;
    string Financials;
    string Utilities;
    string HealthCare;
    string Industrials;
    string RealEstate;
    string Materials;
    string TelecommunicationServices;
    string ConsumerDiscretionary;
    string ConsumerStaples;
    string InformationTechnology;
    string Energy;

public:
    RankB_Type_SECTOR();
    RankB_Type_SECTOR(const RankB_Type_SECTOR& other); // copy constructor

    string get_RankName() const {return RankName;};
    string get_Financials() const {return Financials;};
    string get_Utilities() const {return Utilities;};
    string get_HealthCare() const {return HealthCare;};
    string get_Industrials() const {return Industrials;};
    string get_RealEstate() const {return RealEstate;};
    string get_Materials() const {return Materials;};
    string get_TelecommunicationServices() const {return TelecommunicationServices;};
    string get_ConsumerDiscretionary() const {return ConsumerDiscretionary;};
    string get_ConsumerStaples() const {return ConsumerStaples;};
    string get_InformationTechnology() const {return InformationTechnology;};
    string get_Energy() const {return Energy;};
    void set_RankName(string RankName){this->RankName = RankName;};
    void set_Financials(string Financials){this->Financials = Financials;};
    void set_Utilities(string Utilities){this->Utilities = Utilities;};
    void set_HealthCare(string HealthCare){this->HealthCare = HealthCare;};
    void set_Industrials(string Industrials){this->Industrials = Industrials;};
    void set_RealEstate(string RealEstate){this->RealEstate = RealEstate;};
    void set_Materials(string Materials){this->Materials = Materials;};
    void set_TelecommunicationServices(string TelecommunicationServices){this->TelecommunicationServices = TelecommunicationServices;};
    void set_ConsumerDiscretionary(string ConsumerDiscretionary){this->ConsumerDiscretionary = ConsumerDiscretionary;};
    void set_ConsumerStaples(string ConsumerStaples){this->ConsumerStaples = ConsumerStaples;};
    void set_InformationTechnology(string InformationTechnology){this->InformationTechnology = InformationTechnology;};
    void set_Energy(string Energy){this->Energy = Energy;};

    int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class RankC_Type_SECTOR
{
private:
    string RankName;
    string Financials;
    string Utilities;
    string HealthCare;
    string Industrials;
    string RealEstate;
    string Materials;
    string TelecommunicationServices;
    string ConsumerDiscretionary;
    string ConsumerStaples;
    string InformationTechnology;
    string Energy;

public:
    RankC_Type_SECTOR();
    RankC_Type_SECTOR(const RankC_Type_SECTOR& other); // copy constructor

    string get_RankName() const {return RankName;};
    string get_Financials() const {return Financials;};
    string get_Utilities() const {return Utilities;};
    string get_HealthCare() const {return HealthCare;};
    string get_Industrials() const {return Industrials;};
    string get_RealEstate() const {return RealEstate;};
    string get_Materials() const {return Materials;};
    string get_TelecommunicationServices() const {return TelecommunicationServices;};
    string get_ConsumerDiscretionary() const {return ConsumerDiscretionary;};
    string get_ConsumerStaples() const {return ConsumerStaples;};
    string get_InformationTechnology() const {return InformationTechnology;};
    string get_Energy() const {return Energy;};
    void set_RankName(string RankName){this->RankName = RankName;};
    void set_Financials(string Financials){this->Financials = Financials;};
    void set_Utilities(string Utilities){this->Utilities = Utilities;};
    void set_HealthCare(string HealthCare){this->HealthCare = HealthCare;};
    void set_Industrials(string Industrials){this->Industrials = Industrials;};
    void set_RealEstate(string RealEstate){this->RealEstate = RealEstate;};
    void set_Materials(string Materials){this->Materials = Materials;};
    void set_TelecommunicationServices(string TelecommunicationServices){this->TelecommunicationServices = TelecommunicationServices;};
    void set_ConsumerDiscretionary(string ConsumerDiscretionary){this->ConsumerDiscretionary = ConsumerDiscretionary;};
    void set_ConsumerStaples(string ConsumerStaples){this->ConsumerStaples = ConsumerStaples;};
    void set_InformationTechnology(string InformationTechnology){this->InformationTechnology = InformationTechnology;};
    void set_Energy(string Energy){this->Energy = Energy;};

    int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class RankD_Type_SECTOR
{
private:
    string RankName;
    string Financials;
    string Utilities;
    string HealthCare;
    string Industrials;
    string RealEstate;
    string Materials;
    string TelecommunicationServices;
    string ConsumerDiscretionary;
    string ConsumerStaples;
    string InformationTechnology;
    string Energy;

public:
    RankD_Type_SECTOR();
    RankD_Type_SECTOR(const RankD_Type_SECTOR& other); // copy constructor

    string get_RankName() const {return RankName;};
    string get_Financials() const {return Financials;};
    string get_Utilities() const {return Utilities;};
    string get_HealthCare() const {return HealthCare;};
    string get_Industrials() const {return Industrials;};
    string get_RealEstate() const {return RealEstate;};
    string get_Materials() const {return Materials;};
    string get_TelecommunicationServices() const {return TelecommunicationServices;};
    string get_ConsumerDiscretionary() const {return ConsumerDiscretionary;};
    string get_ConsumerStaples() const {return ConsumerStaples;};
    string get_InformationTechnology() const {return InformationTechnology;};
    string get_Energy() const {return Energy;};
    void set_RankName(string RankName){this->RankName = RankName;};
    void set_Financials(string Financials){this->Financials = Financials;};
    void set_Utilities(string Utilities){this->Utilities = Utilities;};
    void set_HealthCare(string HealthCare){this->HealthCare = HealthCare;};
    void set_Industrials(string Industrials){this->Industrials = Industrials;};
    void set_RealEstate(string RealEstate){this->RealEstate = RealEstate;};
    void set_Materials(string Materials){this->Materials = Materials;};
    void set_TelecommunicationServices(string TelecommunicationServices){this->TelecommunicationServices = TelecommunicationServices;};
    void set_ConsumerDiscretionary(string ConsumerDiscretionary){this->ConsumerDiscretionary = ConsumerDiscretionary;};
    void set_ConsumerStaples(string ConsumerStaples){this->ConsumerStaples = ConsumerStaples;};
    void set_InformationTechnology(string InformationTechnology){this->InformationTechnology = InformationTechnology;};
    void set_Energy(string Energy){this->Energy = Energy;};

    int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class RankE_Type_SECTOR
{
private:
    string RankName;
    string Financials;
    string Utilities;
    string HealthCare;
    string Industrials;
    string RealEstate;
    string Materials;
    string TelecommunicationServices;
    string ConsumerDiscretionary;
    string ConsumerStaples;
    string InformationTechnology;
    string Energy;

public:
    RankE_Type_SECTOR();
    RankE_Type_SECTOR(const RankE_Type_SECTOR& other); // copy constructor

    string get_RankName() const {return RankName;};
    string get_Financials() const {return Financials;};
    string get_Utilities() const {return Utilities;};
    string get_HealthCare() const {return HealthCare;};
    string get_Industrials() const {return Industrials;};
    string get_RealEstate() const {return RealEstate;};
    string get_Materials() const {return Materials;};
    string get_TelecommunicationServices() const {return TelecommunicationServices;};
    string get_ConsumerDiscretionary() const {return ConsumerDiscretionary;};
    string get_ConsumerStaples() const {return ConsumerStaples;};
    string get_InformationTechnology() const {return InformationTechnology;};
    string get_Energy() const {return Energy;};
    void set_RankName(string RankName){this->RankName = RankName;};
    void set_Financials(string Financials){this->Financials = Financials;};
    void set_Utilities(string Utilities){this->Utilities = Utilities;};
    void set_HealthCare(string HealthCare){this->HealthCare = HealthCare;};
    void set_Industrials(string Industrials){this->Industrials = Industrials;};
    void set_RealEstate(string RealEstate){this->RealEstate = RealEstate;};
    void set_Materials(string Materials){this->Materials = Materials;};
    void set_TelecommunicationServices(string TelecommunicationServices){this->TelecommunicationServices = TelecommunicationServices;};
    void set_ConsumerDiscretionary(string ConsumerDiscretionary){this->ConsumerDiscretionary = ConsumerDiscretionary;};
    void set_ConsumerStaples(string ConsumerStaples){this->ConsumerStaples = ConsumerStaples;};
    void set_InformationTechnology(string InformationTechnology){this->InformationTechnology = InformationTechnology;};
    void set_Energy(string Energy){this->Energy = Energy;};

    int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class RankF_Type_SECTOR
{
private:
    string RankName;
    string Financials;
    string Utilities;
    string HealthCare;
    string Industrials;
    string RealEstate;
    string Materials;
    string TelecommunicationServices;
    string ConsumerDiscretionary;
    string ConsumerStaples;
    string InformationTechnology;
    string Energy;

public:
    RankF_Type_SECTOR();
    RankF_Type_SECTOR(const RankF_Type_SECTOR& other); // copy constructor

    string get_RankName() const {return RankName;};
    string get_Financials() const {return Financials;};
    string get_Utilities() const {return Utilities;};
    string get_HealthCare() const {return HealthCare;};
    string get_Industrials() const {return Industrials;};
    string get_RealEstate() const {return RealEstate;};
    string get_Materials() const {return Materials;};
    string get_TelecommunicationServices() const {return TelecommunicationServices;};
    string get_ConsumerDiscretionary() const {return ConsumerDiscretionary;};
    string get_ConsumerStaples() const {return ConsumerStaples;};
    string get_InformationTechnology() const {return InformationTechnology;};
    string get_Energy() const {return Energy;};
    void set_RankName(string RankName){this->RankName = RankName;};
    void set_Financials(string Financials){this->Financials = Financials;};
    void set_Utilities(string Utilities){this->Utilities = Utilities;};
    void set_HealthCare(string HealthCare){this->HealthCare = HealthCare;};
    void set_Industrials(string Industrials){this->Industrials = Industrials;};
    void set_RealEstate(string RealEstate){this->RealEstate = RealEstate;};
    void set_Materials(string Materials){this->Materials = Materials;};
    void set_TelecommunicationServices(string TelecommunicationServices){this->TelecommunicationServices = TelecommunicationServices;};
    void set_ConsumerDiscretionary(string ConsumerDiscretionary){this->ConsumerDiscretionary = ConsumerDiscretionary;};
    void set_ConsumerStaples(string ConsumerStaples){this->ConsumerStaples = ConsumerStaples;};
    void set_InformationTechnology(string InformationTechnology){this->InformationTechnology = InformationTechnology;};
    void set_Energy(string Energy){this->Energy = Energy;};

    int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class RankG_Type_SECTOR
{
private:
    string RankName;
    string Financials;
    string Utilities;
    string HealthCare;
    string Industrials;
    string RealEstate;
    string Materials;
    string TelecommunicationServices;
    string ConsumerDiscretionary;
    string ConsumerStaples;
    string InformationTechnology;
    string Energy;

public:
    RankG_Type_SECTOR();
    RankG_Type_SECTOR(const RankG_Type_SECTOR& other); // copy constructor

    string get_RankName() const {return RankName;};
    string get_Financials() const {return Financials;};
    string get_Utilities() const {return Utilities;};
    string get_HealthCare() const {return HealthCare;};
    string get_Industrials() const {return Industrials;};
    string get_RealEstate() const {return RealEstate;};
    string get_Materials() const {return Materials;};
    string get_TelecommunicationServices() const {return TelecommunicationServices;};
    string get_ConsumerDiscretionary() const {return ConsumerDiscretionary;};
    string get_ConsumerStaples() const {return ConsumerStaples;};
    string get_InformationTechnology() const {return InformationTechnology;};
    string get_Energy() const {return Energy;};
    void set_RankName(string RankName){this->RankName = RankName;};
    void set_Financials(string Financials){this->Financials = Financials;};
    void set_Utilities(string Utilities){this->Utilities = Utilities;};
    void set_HealthCare(string HealthCare){this->HealthCare = HealthCare;};
    void set_Industrials(string Industrials){this->Industrials = Industrials;};
    void set_RealEstate(string RealEstate){this->RealEstate = RealEstate;};
    void set_Materials(string Materials){this->Materials = Materials;};
    void set_TelecommunicationServices(string TelecommunicationServices){this->TelecommunicationServices = TelecommunicationServices;};
    void set_ConsumerDiscretionary(string ConsumerDiscretionary){this->ConsumerDiscretionary = ConsumerDiscretionary;};
    void set_ConsumerStaples(string ConsumerStaples){this->ConsumerStaples = ConsumerStaples;};
    void set_InformationTechnology(string InformationTechnology){this->InformationTechnology = InformationTechnology;};
    void set_Energy(string Energy){this->Energy = Energy;};

    int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class RankH_Type_SECTOR
{
private:
    string RankName;
    string Financials;
    string Utilities;
    string HealthCare;
    string Industrials;
    string Materials;
    string TelecommunicationServices;
    string ConsumerDiscretionary;
    string ConsumerStaples;
    string InformationTechnology;
    string Energy;

public:
    RankH_Type_SECTOR();
    RankH_Type_SECTOR(const RankH_Type_SECTOR& other); // copy constructor

    string get_RankName() const {return RankName;};
    string get_Financials() const {return Financials;};
    string get_Utilities() const {return Utilities;};
    string get_HealthCare() const {return HealthCare;};
    string get_Industrials() const {return Industrials;};
    string get_Materials() const {return Materials;};
    string get_TelecommunicationServices() const {return TelecommunicationServices;};
    string get_ConsumerDiscretionary() const {return ConsumerDiscretionary;};
    string get_ConsumerStaples() const {return ConsumerStaples;};
    string get_InformationTechnology() const {return InformationTechnology;};
    string get_Energy() const {return Energy;};
    void set_RankName(string RankName){this->RankName = RankName;};
    void set_Financials(string Financials){this->Financials = Financials;};
    void set_Utilities(string Utilities){this->Utilities = Utilities;};
    void set_HealthCare(string HealthCare){this->HealthCare = HealthCare;};
    void set_Industrials(string Industrials){this->Industrials = Industrials;};
    void set_Materials(string Materials){this->Materials = Materials;};
    void set_TelecommunicationServices(string TelecommunicationServices){this->TelecommunicationServices = TelecommunicationServices;};
    void set_ConsumerDiscretionary(string ConsumerDiscretionary){this->ConsumerDiscretionary = ConsumerDiscretionary;};
    void set_ConsumerStaples(string ConsumerStaples){this->ConsumerStaples = ConsumerStaples;};
    void set_InformationTechnology(string InformationTechnology){this->InformationTechnology = InformationTechnology;};
    void set_Energy(string Energy){this->Energy = Energy;};

    int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class RankI_Type_SECTOR
{
private:
    string RankName;
    string Financials;
    string Utilities;
    string HealthCare;
    string Industrials;
    string Materials;
    string TelecommunicationServices;
    string ConsumerDiscretionary;
    string ConsumerStaples;
    string InformationTechnology;
    string Energy;

public:
    RankI_Type_SECTOR();
    RankI_Type_SECTOR(const RankI_Type_SECTOR& other); // copy constructor

    string get_RankName() const {return RankName;};
    string get_Financials() const {return Financials;};
    string get_Utilities() const {return Utilities;};
    string get_HealthCare() const {return HealthCare;};
    string get_Industrials() const {return Industrials;};
    string get_Materials() const {return Materials;};
    string get_TelecommunicationServices() const {return TelecommunicationServices;};
    string get_ConsumerDiscretionary() const {return ConsumerDiscretionary;};
    string get_ConsumerStaples() const {return ConsumerStaples;};
    string get_InformationTechnology() const {return InformationTechnology;};
    string get_Energy() const {return Energy;};
    void set_RankName(string RankName){this->RankName = RankName;};
    void set_Financials(string Financials){this->Financials = Financials;};
    void set_Utilities(string Utilities){this->Utilities = Utilities;};
    void set_HealthCare(string HealthCare){this->HealthCare = HealthCare;};
    void set_Industrials(string Industrials){this->Industrials = Industrials;};
    void set_Materials(string Materials){this->Materials = Materials;};
    void set_TelecommunicationServices(string TelecommunicationServices){this->TelecommunicationServices = TelecommunicationServices;};
    void set_ConsumerDiscretionary(string ConsumerDiscretionary){this->ConsumerDiscretionary = ConsumerDiscretionary;};
    void set_ConsumerStaples(string ConsumerStaples){this->ConsumerStaples = ConsumerStaples;};
    void set_InformationTechnology(string InformationTechnology){this->InformationTechnology = InformationTechnology;};
    void set_Energy(string Energy){this->Energy = Energy;};

    int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class RankJ_Type_SECTOR
{
private:
    string RankName;
    string Financials;
    string Utilities;
    string HealthCare;
    string Industrials;
    string Materials;
    string TelecommunicationServices;
    string ConsumerDiscretionary;
    string ConsumerStaples;
    string InformationTechnology;
    string Energy;

public:
    RankJ_Type_SECTOR();
    RankJ_Type_SECTOR(const RankJ_Type_SECTOR& other); // copy constructor

    string get_RankName() const {return RankName;};
    string get_Financials() const {return Financials;};
    string get_Utilities() const {return Utilities;};
    string get_HealthCare() const {return HealthCare;};
    string get_Industrials() const {return Industrials;};
    string get_Materials() const {return Materials;};
    string get_TelecommunicationServices() const {return TelecommunicationServices;};
    string get_ConsumerDiscretionary() const {return ConsumerDiscretionary;};
    string get_ConsumerStaples() const {return ConsumerStaples;};
    string get_InformationTechnology() const {return InformationTechnology;};
    string get_Energy() const {return Energy;};
    void set_RankName(string RankName){this->RankName = RankName;};
    void set_Financials(string Financials){this->Financials = Financials;};
    void set_Utilities(string Utilities){this->Utilities = Utilities;};
    void set_HealthCare(string HealthCare){this->HealthCare = HealthCare;};
    void set_Industrials(string Industrials){this->Industrials = Industrials;};
    void set_Materials(string Materials){this->Materials = Materials;};
    void set_TelecommunicationServices(string TelecommunicationServices){this->TelecommunicationServices = TelecommunicationServices;};
    void set_ConsumerDiscretionary(string ConsumerDiscretionary){this->ConsumerDiscretionary = ConsumerDiscretionary;};
    void set_ConsumerStaples(string ConsumerStaples){this->ConsumerStaples = ConsumerStaples;};
    void set_InformationTechnology(string InformationTechnology){this->InformationTechnology = InformationTechnology;};
    void set_Energy(string Energy){this->Energy = Energy;};

    int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_SECTOR_Content
{
private:
    MetaData_Type_SECTOR MetaData;
    RankA_Type_SECTOR RankA;
    RankB_Type_SECTOR RankB;
    RankC_Type_SECTOR RankC;
    RankD_Type_SECTOR RankD;
    RankE_Type_SECTOR RankE;
    RankF_Type_SECTOR RankF;
    RankG_Type_SECTOR RankG;
    RankH_Type_SECTOR RankH;
    RankI_Type_SECTOR RankI;
    RankJ_Type_SECTOR RankJ;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_SECTOR_Content();
    ~AvapiResponse_SECTOR_Content() {};
    AvapiResponse_SECTOR_Content(const AvapiResponse_SECTOR_Content& other); // copy constructor
    MetaData_Type_SECTOR& get_MetaData() {return MetaData;};
    RankA_Type_SECTOR& get_RankA() {return RankA;};
    RankB_Type_SECTOR& get_RankB() {return RankB;};
    RankC_Type_SECTOR& get_RankC() {return RankC;};
    RankD_Type_SECTOR& get_RankD() {return RankD;};
    RankE_Type_SECTOR& get_RankE() {return RankE;};
    RankF_Type_SECTOR& get_RankF() {return RankF;};
    RankG_Type_SECTOR& get_RankG() {return RankG;};
    RankH_Type_SECTOR& get_RankH() {return RankH;};
    RankI_Type_SECTOR& get_RankI() {return RankI;};
    RankJ_Type_SECTOR& get_RankJ() {return RankJ;};

    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_SECTOR
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_SECTOR_Content* Data;

public:
    AvapiResponse_SECTOR();
    AvapiResponse_SECTOR(const AvapiResponse_SECTOR& other); // copy constructor
    AvapiResponse_SECTOR(AvapiResponse_SECTOR&& other); // move constructor
    AvapiResponse_SECTOR& operator=(const AvapiResponse_SECTOR& other); //copy assignment
    AvapiResponse_SECTOR& operator=(AvapiResponse_SECTOR&& other); //move assignment
    ~AvapiResponse_SECTOR();

    AvapiResponse_SECTOR_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_SECTOR
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_SECTOR *s_instance;
    Impl_SECTOR() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_SECTOR& Response);

public:
    static Impl_SECTOR& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_SECTOR Query();
};

}//end namespace Avapi

#endif // SECTOR_HPP_INCLUDED
