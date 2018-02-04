#ifndef ADOSC_HPP_INCLUDED
#define ADOSC_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_ADOSC_interval{
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

class MAP_ADOSC
{
public:
    static const map<Const_ADOSC_interval, string> s_interval_translation;
};

class MetaData_Type_ADOSC
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string FastKPeriod;
    string SlowKPeriod;
    string TimeZone;

public:
    MetaData_Type_ADOSC();
    MetaData_Type_ADOSC(const MetaData_Type_ADOSC& other); // copy constructor
    
    string get_Symbol() const {return Symbol;};
    string get_Indicator() const {return Indicator;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_Interval() const {return Interval;};
    string get_FastKPeriod() const {return FastKPeriod;};
    string get_SlowKPeriod() const {return SlowKPeriod;};
    string get_TimeZone() const {return TimeZone;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Indicator(string Indicator){this->Indicator = Indicator;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_FastKPeriod(string FastKPeriod){this->FastKPeriod = FastKPeriod;};
    void set_SlowKPeriod(string SlowKPeriod){this->SlowKPeriod = SlowKPeriod;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TechnicalIndicator_Type_ADOSC
{
private:
    string ADOSC;
    string DateTime;

public:
    TechnicalIndicator_Type_ADOSC();
    TechnicalIndicator_Type_ADOSC(const TechnicalIndicator_Type_ADOSC& other); // copy constructor

    string get_ADOSC() const {return ADOSC;};
    string get_DateTime() const {return DateTime;};
    void set_ADOSC(string ADOSC){this->ADOSC = ADOSC;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_ADOSC_Content
{
private:
    MetaData_Type_ADOSC MetaData;
    list<TechnicalIndicator_Type_ADOSC> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_ADOSC_Content();
    ~AvapiResponse_ADOSC_Content() {};
    AvapiResponse_ADOSC_Content(const AvapiResponse_ADOSC_Content& other); // copy constructor
    MetaData_Type_ADOSC& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_ADOSC>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_ADOSC
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_ADOSC_Content* Data;

public:
    AvapiResponse_ADOSC();
    AvapiResponse_ADOSC(const AvapiResponse_ADOSC& other); // copy constructor
    AvapiResponse_ADOSC(AvapiResponse_ADOSC&& other); // move constructor
    AvapiResponse_ADOSC& operator=(const AvapiResponse_ADOSC& other); //copy assignment
    AvapiResponse_ADOSC& operator=(AvapiResponse_ADOSC&& other); //move assignment
    ~AvapiResponse_ADOSC();

    AvapiResponse_ADOSC_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_ADOSC
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_ADOSC *s_instance;
    Impl_ADOSC() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_ADOSC& Response);

public:
    static Impl_ADOSC& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_ADOSC Query(string symbol
        ,Const_ADOSC_interval interval
        ,string fastperiod
        ,string slowperiod
        );
        
    AvapiResponse_ADOSC Query(string symbol
        ,string interval
        ,string fastperiod
        ,string slowperiod
        );
};

}//end namespace Avapi

#endif // ADOSC_HPP_INCLUDED
