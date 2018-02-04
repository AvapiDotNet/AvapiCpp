#ifndef HT_TRENDLINE_HPP_INCLUDED
#define HT_TRENDLINE_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_HT_TRENDLINE_interval{
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

enum class Const_HT_TRENDLINE_series_type{
    none,
    close,
    open,
    high,
    low,
};

class MAP_HT_TRENDLINE
{
public:
    static const map<Const_HT_TRENDLINE_interval, string> s_interval_translation;
    static const map<Const_HT_TRENDLINE_series_type, string> s_series_type_translation;
};

class MetaData_Type_HT_TRENDLINE
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string SeriesType;
    string TimeZone;

public:
    MetaData_Type_HT_TRENDLINE();
    MetaData_Type_HT_TRENDLINE(const MetaData_Type_HT_TRENDLINE& other); // copy constructor
    
    string get_Symbol() const {return Symbol;};
    string get_Indicator() const {return Indicator;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_Interval() const {return Interval;};
    string get_SeriesType() const {return SeriesType;};
    string get_TimeZone() const {return TimeZone;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Indicator(string Indicator){this->Indicator = Indicator;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_SeriesType(string SeriesType){this->SeriesType = SeriesType;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TechnicalIndicator_Type_HT_TRENDLINE
{
private:
    string HT_TRENDLINE;
    string DateTime;

public:
    TechnicalIndicator_Type_HT_TRENDLINE();
    TechnicalIndicator_Type_HT_TRENDLINE(const TechnicalIndicator_Type_HT_TRENDLINE& other); // copy constructor

    string get_HT_TRENDLINE() const {return HT_TRENDLINE;};
    string get_DateTime() const {return DateTime;};
    void set_HT_TRENDLINE(string HT_TRENDLINE){this->HT_TRENDLINE = HT_TRENDLINE;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_HT_TRENDLINE_Content
{
private:
    MetaData_Type_HT_TRENDLINE MetaData;
    list<TechnicalIndicator_Type_HT_TRENDLINE> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_HT_TRENDLINE_Content();
    ~AvapiResponse_HT_TRENDLINE_Content() {};
    AvapiResponse_HT_TRENDLINE_Content(const AvapiResponse_HT_TRENDLINE_Content& other); // copy constructor
    MetaData_Type_HT_TRENDLINE& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_HT_TRENDLINE>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_HT_TRENDLINE
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_HT_TRENDLINE_Content* Data;

public:
    AvapiResponse_HT_TRENDLINE();
    AvapiResponse_HT_TRENDLINE(const AvapiResponse_HT_TRENDLINE& other); // copy constructor
    AvapiResponse_HT_TRENDLINE(AvapiResponse_HT_TRENDLINE&& other); // move constructor
    AvapiResponse_HT_TRENDLINE& operator=(const AvapiResponse_HT_TRENDLINE& other); //copy assignment
    AvapiResponse_HT_TRENDLINE& operator=(AvapiResponse_HT_TRENDLINE&& other); //move assignment
    ~AvapiResponse_HT_TRENDLINE();

    AvapiResponse_HT_TRENDLINE_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_HT_TRENDLINE
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_HT_TRENDLINE *s_instance;
    Impl_HT_TRENDLINE() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_HT_TRENDLINE& Response);

public:
    static Impl_HT_TRENDLINE& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_HT_TRENDLINE Query(string symbol
        ,Const_HT_TRENDLINE_interval interval
        ,Const_HT_TRENDLINE_series_type series_type
        );
        
    AvapiResponse_HT_TRENDLINE Query(string symbol
        ,string interval
        ,string series_type
        );
};

}//end namespace Avapi

#endif // HT_TRENDLINE_HPP_INCLUDED
