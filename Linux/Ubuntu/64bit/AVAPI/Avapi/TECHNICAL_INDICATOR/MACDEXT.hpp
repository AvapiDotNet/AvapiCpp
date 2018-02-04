#ifndef MACDEXT_HPP_INCLUDED
#define MACDEXT_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_MACDEXT_interval{
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

enum class Const_MACDEXT_series_type{
    none,
    close,
    open,
    high,
    low,
};

enum class Const_MACDEXT_fastmatype{
    none,
    n_0,
    n_1,
    n_2,
    n_3,
    n_4,
    n_5,
    n_6,
    n_7,
    n_8,
};

enum class Const_MACDEXT_slowmatype{
    none,
    n_0,
    n_1,
    n_2,
    n_3,
    n_4,
    n_5,
    n_6,
    n_7,
    n_8,
};

enum class Const_MACDEXT_signalmatype{
    none,
    n_0,
    n_1,
    n_2,
    n_3,
    n_4,
    n_5,
    n_6,
    n_7,
    n_8,
};

class MAP_MACDEXT
{
public:
    static const map<Const_MACDEXT_interval, string> s_interval_translation;
    static const map<Const_MACDEXT_series_type, string> s_series_type_translation;
    static const map<Const_MACDEXT_fastmatype, string> s_fastmatype_translation;
    static const map<Const_MACDEXT_slowmatype, string> s_slowmatype_translation;
    static const map<Const_MACDEXT_signalmatype, string> s_signalmatype_translation;
};

class MetaData_Type_MACDEXT
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string FastPeriod;
    string SlowPeriod;
    string SignalPeriod;
    string FastMAType;
    string SlowMAType;
    string SignalMAType;
    string SeriesType;
    string TimeZone;

public:
    MetaData_Type_MACDEXT();
    MetaData_Type_MACDEXT(const MetaData_Type_MACDEXT& other); // copy constructor
    
    string get_Symbol() const {return Symbol;};
    string get_Indicator() const {return Indicator;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_Interval() const {return Interval;};
    string get_FastPeriod() const {return FastPeriod;};
    string get_SlowPeriod() const {return SlowPeriod;};
    string get_SignalPeriod() const {return SignalPeriod;};
    string get_FastMAType() const {return FastMAType;};
    string get_SlowMAType() const {return SlowMAType;};
    string get_SignalMAType() const {return SignalMAType;};
    string get_SeriesType() const {return SeriesType;};
    string get_TimeZone() const {return TimeZone;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Indicator(string Indicator){this->Indicator = Indicator;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_FastPeriod(string FastPeriod){this->FastPeriod = FastPeriod;};
    void set_SlowPeriod(string SlowPeriod){this->SlowPeriod = SlowPeriod;};
    void set_SignalPeriod(string SignalPeriod){this->SignalPeriod = SignalPeriod;};
    void set_FastMAType(string FastMAType){this->FastMAType = FastMAType;};
    void set_SlowMAType(string SlowMAType){this->SlowMAType = SlowMAType;};
    void set_SignalMAType(string SignalMAType){this->SignalMAType = SignalMAType;};
    void set_SeriesType(string SeriesType){this->SeriesType = SeriesType;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TechnicalIndicator_Type_MACDEXT
{
private:
    string MACD;
    string MACD_Hist;
    string MACD_Signal;
    string DateTime;

public:
    TechnicalIndicator_Type_MACDEXT();
    TechnicalIndicator_Type_MACDEXT(const TechnicalIndicator_Type_MACDEXT& other); // copy constructor

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

class AvapiResponse_MACDEXT_Content
{
private:
    MetaData_Type_MACDEXT MetaData;
    list<TechnicalIndicator_Type_MACDEXT> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_MACDEXT_Content();
    ~AvapiResponse_MACDEXT_Content() {};
    AvapiResponse_MACDEXT_Content(const AvapiResponse_MACDEXT_Content& other); // copy constructor
    MetaData_Type_MACDEXT& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_MACDEXT>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_MACDEXT
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_MACDEXT_Content* Data;

public:
    AvapiResponse_MACDEXT();
    AvapiResponse_MACDEXT(const AvapiResponse_MACDEXT& other); // copy constructor
    AvapiResponse_MACDEXT(AvapiResponse_MACDEXT&& other); // move constructor
    AvapiResponse_MACDEXT& operator=(const AvapiResponse_MACDEXT& other); //copy assignment
    AvapiResponse_MACDEXT& operator=(AvapiResponse_MACDEXT&& other); //move assignment
    ~AvapiResponse_MACDEXT();

    AvapiResponse_MACDEXT_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_MACDEXT
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_MACDEXT *s_instance;
    Impl_MACDEXT() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_MACDEXT& Response);

public:
    static Impl_MACDEXT& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_MACDEXT Query(string symbol
        ,Const_MACDEXT_interval interval
        ,Const_MACDEXT_series_type series_type
        ,string fastperiod
        ,string slowperiod
        ,string signalperiod
        ,Const_MACDEXT_fastmatype fastmatype
        ,Const_MACDEXT_slowmatype slowmatype
        ,Const_MACDEXT_signalmatype signalmatype
        );
        
    AvapiResponse_MACDEXT Query(string symbol
        ,string interval
        ,string series_type
        ,string fastperiod
        ,string slowperiod
        ,string signalperiod
        ,string fastmatype
        ,string slowmatype
        ,string signalmatype
        );
};

}//end namespace Avapi

#endif // MACDEXT_HPP_INCLUDED
