#ifndef MACD_HPP_INCLUDED
#define MACD_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_MACD_interval{
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

enum class Const_MACD_series_type{
    none,
    close,
    open,
    high,
    low,
};

class MAP_MACD
{
public:
    static const map<Const_MACD_interval, string> s_interval_translation;
    static const map<Const_MACD_series_type, string> s_series_type_translation;
};

class MetaData_Type_MACD
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string FastPeriod;
    string SlowPeriod;
    string SignalPeriod;
    string SeriesType;
    string TimeZone;

public:
    MetaData_Type_MACD();
    MetaData_Type_MACD(const MetaData_Type_MACD& other); // copy constructor
    
    string get_Symbol() const {return Symbol;};
    string get_Indicator() const {return Indicator;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_Interval() const {return Interval;};
    string get_FastPeriod() const {return FastPeriod;};
    string get_SlowPeriod() const {return SlowPeriod;};
    string get_SignalPeriod() const {return SignalPeriod;};
    string get_SeriesType() const {return SeriesType;};
    string get_TimeZone() const {return TimeZone;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Indicator(string Indicator){this->Indicator = Indicator;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_FastPeriod(string FastPeriod){this->FastPeriod = FastPeriod;};
    void set_SlowPeriod(string SlowPeriod){this->SlowPeriod = SlowPeriod;};
    void set_SignalPeriod(string SignalPeriod){this->SignalPeriod = SignalPeriod;};
    void set_SeriesType(string SeriesType){this->SeriesType = SeriesType;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TechnicalIndicator_Type_MACD
{
private:
    string MACD;
    string MACD_Hist;
    string MACD_Signal;
    string DateTime;

public:
    TechnicalIndicator_Type_MACD();
    TechnicalIndicator_Type_MACD(const TechnicalIndicator_Type_MACD& other); // copy constructor

    string get_MACD() const {return MACD;};
    string get_MACD_Hist() const {return MACD_Hist;};
    string get_MACD_Signal() const {return MACD_Signal;};
    string get_DateTime() const {return DateTime;};
    void set_MACD(string MACD){this->MACD = MACD;};
    void set_MACD_Hist(string MACD_Hist){this->MACD_Hist = MACD_Hist;};
    void set_MACD_Signal(string MACD_Signal){this->MACD_Signal = MACD_Signal;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_MACD_Content
{
private:
    MetaData_Type_MACD MetaData;
    list<TechnicalIndicator_Type_MACD> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_MACD_Content();
    ~AvapiResponse_MACD_Content() {};
    AvapiResponse_MACD_Content(const AvapiResponse_MACD_Content& other); // copy constructor
    MetaData_Type_MACD& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_MACD>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_MACD
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_MACD_Content* Data;

public:
    AvapiResponse_MACD();
    AvapiResponse_MACD(const AvapiResponse_MACD& other); // copy constructor
    AvapiResponse_MACD(AvapiResponse_MACD&& other); // move constructor
    AvapiResponse_MACD& operator=(const AvapiResponse_MACD& other); //copy assignment
    AvapiResponse_MACD& operator=(AvapiResponse_MACD&& other); //move assignment
    ~AvapiResponse_MACD();

    AvapiResponse_MACD_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_MACD
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_MACD *s_instance;
    Impl_MACD() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_MACD& Response);

public:
    static Impl_MACD& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_MACD Query(string symbol
        ,Const_MACD_interval interval
        ,Const_MACD_series_type series_type
        ,string fastperiod
        ,string slowperiod
        ,string signalperiod
        );
        
    AvapiResponse_MACD Query(string symbol
        ,string interval
        ,string series_type
        ,string fastperiod
        ,string slowperiod
        ,string signalperiod
        );
};

}//end namespace Avapi

#endif // MACD_HPP_INCLUDED
