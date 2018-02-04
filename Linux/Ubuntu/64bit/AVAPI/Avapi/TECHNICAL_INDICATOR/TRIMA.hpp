#ifndef TRIMA_HPP_INCLUDED
#define TRIMA_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_TRIMA_interval{
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

enum class Const_TRIMA_series_type{
    none,
    close,
    open,
    high,
    low,
};

class MAP_TRIMA
{
public:
    static const map<Const_TRIMA_interval, string> s_interval_translation;
    static const map<Const_TRIMA_series_type, string> s_series_type_translation;
};

class MetaData_Type_TRIMA
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
    MetaData_Type_TRIMA();
    MetaData_Type_TRIMA(const MetaData_Type_TRIMA& other); // copy constructor
    
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

class TechnicalIndicator_Type_TRIMA
{
private:
    string TRIMA;
    string DateTime;

public:
    TechnicalIndicator_Type_TRIMA();
    TechnicalIndicator_Type_TRIMA(const TechnicalIndicator_Type_TRIMA& other); // copy constructor

    string get_TRIMA() const {return TRIMA;};
    string get_DateTime() const {return DateTime;};
    void set_TRIMA(string TRIMA){this->TRIMA = TRIMA;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_TRIMA_Content
{
private:
    MetaData_Type_TRIMA MetaData;
    list<TechnicalIndicator_Type_TRIMA> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_TRIMA_Content();
    ~AvapiResponse_TRIMA_Content() {};
    AvapiResponse_TRIMA_Content(const AvapiResponse_TRIMA_Content& other); // copy constructor
    MetaData_Type_TRIMA& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_TRIMA>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_TRIMA
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_TRIMA_Content* Data;

public:
    AvapiResponse_TRIMA();
    AvapiResponse_TRIMA(const AvapiResponse_TRIMA& other); // copy constructor
    AvapiResponse_TRIMA(AvapiResponse_TRIMA&& other); // move constructor
    AvapiResponse_TRIMA& operator=(const AvapiResponse_TRIMA& other); //copy assignment
    AvapiResponse_TRIMA& operator=(AvapiResponse_TRIMA&& other); //move assignment
    ~AvapiResponse_TRIMA();

    AvapiResponse_TRIMA_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_TRIMA
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_TRIMA *s_instance;
    Impl_TRIMA() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_TRIMA& Response);

public:
    static Impl_TRIMA& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_TRIMA Query(string symbol
        ,Const_TRIMA_interval interval
        ,string time_period
        ,Const_TRIMA_series_type series_type
        );
        
    AvapiResponse_TRIMA Query(string symbol
        ,string interval
        ,string time_period
        ,string series_type
        );
};

}//end namespace Avapi

#endif // TRIMA_HPP_INCLUDED
