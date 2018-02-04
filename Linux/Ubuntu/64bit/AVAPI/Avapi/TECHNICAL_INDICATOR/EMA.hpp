#ifndef EMA_HPP_INCLUDED
#define EMA_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_EMA_interval{
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

enum class Const_EMA_series_type{
    none,
    close,
    open,
    high,
    low,
};

class MAP_EMA
{
public:
    static const map<Const_EMA_interval, string> s_interval_translation;
    static const map<Const_EMA_series_type, string> s_series_type_translation;
};

class MetaData_Type_EMA
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string TimePeriod;
    string SeriesType;
    string TimeZone;

public:
    MetaData_Type_EMA();
    MetaData_Type_EMA(const MetaData_Type_EMA& other); // copy constructor
    
    string get_Symbol() const {return Symbol;};
    string get_Indicator() const {return Indicator;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_Interval() const {return Interval;};
    string get_TimePeriod() const {return TimePeriod;};
    string get_SeriesType() const {return SeriesType;};
    string get_TimeZone() const {return TimeZone;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Indicator(string Indicator){this->Indicator = Indicator;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_TimePeriod(string TimePeriod){this->TimePeriod = TimePeriod;};
    void set_SeriesType(string SeriesType){this->SeriesType = SeriesType;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TechnicalIndicator_Type_EMA
{
private:
    string EMA;
    string DateTime;

public:
    TechnicalIndicator_Type_EMA();
    TechnicalIndicator_Type_EMA(const TechnicalIndicator_Type_EMA& other); // copy constructor

    string get_EMA() const {return EMA;};
    string get_DateTime() const {return DateTime;};
    void set_EMA(string EMA){this->EMA = EMA;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_EMA_Content
{
private:
    MetaData_Type_EMA MetaData;
    list<TechnicalIndicator_Type_EMA> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_EMA_Content();
    ~AvapiResponse_EMA_Content() {};
    AvapiResponse_EMA_Content(const AvapiResponse_EMA_Content& other); // copy constructor
    MetaData_Type_EMA& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_EMA>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_EMA
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_EMA_Content* Data;

public:
    AvapiResponse_EMA();
    AvapiResponse_EMA(const AvapiResponse_EMA& other); // copy constructor
    AvapiResponse_EMA(AvapiResponse_EMA&& other); // move constructor
    AvapiResponse_EMA& operator=(const AvapiResponse_EMA& other); //copy assignment
    AvapiResponse_EMA& operator=(AvapiResponse_EMA&& other); //move assignment
    ~AvapiResponse_EMA();

    AvapiResponse_EMA_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_EMA
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_EMA *s_instance;
    Impl_EMA() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_EMA& Response);

public:
    static Impl_EMA& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_EMA Query(string symbol
        ,Const_EMA_interval interval
        ,string time_period
        ,Const_EMA_series_type series_type
        );
        
    AvapiResponse_EMA Query(string symbol
        ,string interval
        ,string time_period
        ,string series_type
        );
};

}//end namespace Avapi

#endif // EMA_HPP_INCLUDED
