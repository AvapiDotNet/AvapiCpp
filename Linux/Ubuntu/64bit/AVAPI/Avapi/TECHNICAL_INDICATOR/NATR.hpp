#ifndef NATR_HPP_INCLUDED
#define NATR_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_NATR_interval{
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

class MAP_NATR
{
public:
    static const map<Const_NATR_interval, string> s_interval_translation;
};

class MetaData_Type_NATR
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string TimePeriod;
    string TimeZone;

public:
    MetaData_Type_NATR();
    MetaData_Type_NATR(const MetaData_Type_NATR& other); // copy constructor
    
    string get_Symbol() const {return Symbol;};
    string get_Indicator() const {return Indicator;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_Interval() const {return Interval;};
    string get_TimePeriod() const {return TimePeriod;};
    string get_TimeZone() const {return TimeZone;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Indicator(string Indicator){this->Indicator = Indicator;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_TimePeriod(string TimePeriod){this->TimePeriod = TimePeriod;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TechnicalIndicator_Type_NATR
{
private:
    string NATR;
    string DateTime;

public:
    TechnicalIndicator_Type_NATR();
    TechnicalIndicator_Type_NATR(const TechnicalIndicator_Type_NATR& other); // copy constructor

    string get_NATR() const {return NATR;};
    string get_DateTime() const {return DateTime;};
    void set_NATR(string NATR){this->NATR = NATR;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_NATR_Content
{
private:
    MetaData_Type_NATR MetaData;
    list<TechnicalIndicator_Type_NATR> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_NATR_Content();
    ~AvapiResponse_NATR_Content() {};
    AvapiResponse_NATR_Content(const AvapiResponse_NATR_Content& other); // copy constructor
    MetaData_Type_NATR& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_NATR>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_NATR
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_NATR_Content* Data;

public:
    AvapiResponse_NATR();
    AvapiResponse_NATR(const AvapiResponse_NATR& other); // copy constructor
    AvapiResponse_NATR(AvapiResponse_NATR&& other); // move constructor
    AvapiResponse_NATR& operator=(const AvapiResponse_NATR& other); //copy assignment
    AvapiResponse_NATR& operator=(AvapiResponse_NATR&& other); //move assignment
    ~AvapiResponse_NATR();

    AvapiResponse_NATR_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_NATR
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_NATR *s_instance;
    Impl_NATR() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_NATR& Response);

public:
    static Impl_NATR& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_NATR Query(string symbol
        ,Const_NATR_interval interval
        ,string time_period
        );
        
    AvapiResponse_NATR Query(string symbol
        ,string interval
        ,string time_period
        );
};

}//end namespace Avapi

#endif // NATR_HPP_INCLUDED
