#ifndef OBV_HPP_INCLUDED
#define OBV_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_OBV_interval{
    none,
    n_1min,
    n_5min,
    n_15min,
    n_30min,
    n_60min,
    daily,
    weekly,
    monthly,
};

class MAP_OBV
{
public:
    static const map<Const_OBV_interval, string> s_interval_translation;
};

class MetaData_Type_OBV
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string TimeZone;

public:
    MetaData_Type_OBV();
    MetaData_Type_OBV(const MetaData_Type_OBV& other); // copy constructor
    
    string get_Symbol() const {return Symbol;};
    string get_Indicator() const {return Indicator;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_Interval() const {return Interval;};
    string get_TimeZone() const {return TimeZone;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Indicator(string Indicator){this->Indicator = Indicator;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TechnicalIndicator_Type_OBV
{
private:
    string OBV;
    string DateTime;

public:
    TechnicalIndicator_Type_OBV();
    TechnicalIndicator_Type_OBV(const TechnicalIndicator_Type_OBV& other); // copy constructor

    string get_OBV() const {return OBV;};
    string get_DateTime() const {return DateTime;};
    void set_OBV(string OBV){this->OBV = OBV;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_OBV_Content
{
private:
    MetaData_Type_OBV MetaData;
    list<TechnicalIndicator_Type_OBV> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_OBV_Content();
    ~AvapiResponse_OBV_Content() {};
    AvapiResponse_OBV_Content(const AvapiResponse_OBV_Content& other); // copy constructor
    MetaData_Type_OBV& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_OBV>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_OBV
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_OBV_Content* Data;

public:
    AvapiResponse_OBV();
    AvapiResponse_OBV(const AvapiResponse_OBV& other); // copy constructor
    AvapiResponse_OBV(AvapiResponse_OBV&& other); // move constructor
    AvapiResponse_OBV& operator=(const AvapiResponse_OBV& other); //copy assignment
    AvapiResponse_OBV& operator=(AvapiResponse_OBV&& other); //move assignment
    ~AvapiResponse_OBV();

    AvapiResponse_OBV_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_OBV
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_OBV *s_instance;
    Impl_OBV() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_OBV& Response);

public:
    static Impl_OBV& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_OBV Query(string symbol
        ,Const_OBV_interval interval
        );
        
    AvapiResponse_OBV Query(string symbol
        ,string interval
        );
};

}//end namespace Avapi

#endif // OBV_HPP_INCLUDED
