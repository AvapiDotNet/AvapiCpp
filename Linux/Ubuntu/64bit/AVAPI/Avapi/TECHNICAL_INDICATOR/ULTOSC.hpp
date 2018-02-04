#ifndef ULTOSC_HPP_INCLUDED
#define ULTOSC_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_ULTOSC_interval{
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

class MAP_ULTOSC
{
public:
    static const map<Const_ULTOSC_interval, string> s_interval_translation;
};

class MetaData_Type_ULTOSC
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string TimePeriod1;
    string TimePeriod2;
    string TimePeriod3;
    string TimeZone;

public:
    MetaData_Type_ULTOSC();
    MetaData_Type_ULTOSC(const MetaData_Type_ULTOSC& other); // copy constructor
    
    string get_Symbol() const {return Symbol;};
    string get_Indicator() const {return Indicator;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_Interval() const {return Interval;};
    string get_TimePeriod1() const {return TimePeriod1;};
    string get_TimePeriod2() const {return TimePeriod2;};
    string get_TimePeriod3() const {return TimePeriod3;};
    string get_TimeZone() const {return TimeZone;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Indicator(string Indicator){this->Indicator = Indicator;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_TimePeriod1(string TimePeriod1){this->TimePeriod1 = TimePeriod1;};
    void set_TimePeriod2(string TimePeriod2){this->TimePeriod2 = TimePeriod2;};
    void set_TimePeriod3(string TimePeriod3){this->TimePeriod3 = TimePeriod3;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TechnicalIndicator_Type_ULTOSC
{
private:
    string ULTOSC;
    string DateTime;

public:
    TechnicalIndicator_Type_ULTOSC();
    TechnicalIndicator_Type_ULTOSC(const TechnicalIndicator_Type_ULTOSC& other); // copy constructor

    string get_ULTOSC() const {return ULTOSC;};
    string get_DateTime() const {return DateTime;};
    void set_ULTOSC(string ULTOSC){this->ULTOSC = ULTOSC;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_ULTOSC_Content
{
private:
    MetaData_Type_ULTOSC MetaData;
    list<TechnicalIndicator_Type_ULTOSC> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_ULTOSC_Content();
    ~AvapiResponse_ULTOSC_Content() {};
    AvapiResponse_ULTOSC_Content(const AvapiResponse_ULTOSC_Content& other); // copy constructor
    MetaData_Type_ULTOSC& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_ULTOSC>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_ULTOSC
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_ULTOSC_Content* Data;

public:
    AvapiResponse_ULTOSC();
    AvapiResponse_ULTOSC(const AvapiResponse_ULTOSC& other); // copy constructor
    AvapiResponse_ULTOSC(AvapiResponse_ULTOSC&& other); // move constructor
    AvapiResponse_ULTOSC& operator=(const AvapiResponse_ULTOSC& other); //copy assignment
    AvapiResponse_ULTOSC& operator=(AvapiResponse_ULTOSC&& other); //move assignment
    ~AvapiResponse_ULTOSC();

    AvapiResponse_ULTOSC_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_ULTOSC
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_ULTOSC *s_instance;
    Impl_ULTOSC() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_ULTOSC& Response);

public:
    static Impl_ULTOSC& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_ULTOSC Query(string symbol
        ,Const_ULTOSC_interval interval
        ,string timeperiod1
        ,string timeperiod2
        ,string timeperiod3
        );
        
    AvapiResponse_ULTOSC Query(string symbol
        ,string interval
        ,string timeperiod1
        ,string timeperiod2
        ,string timeperiod3
        );
};

}//end namespace Avapi

#endif // ULTOSC_HPP_INCLUDED
