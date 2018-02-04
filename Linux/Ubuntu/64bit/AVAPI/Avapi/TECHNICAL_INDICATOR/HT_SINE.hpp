#ifndef HT_SINE_HPP_INCLUDED
#define HT_SINE_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_HT_SINE_interval{
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

enum class Const_HT_SINE_series_type{
    none,
    close,
    open,
    high,
    low,
};

class MAP_HT_SINE
{
public:
    static const map<Const_HT_SINE_interval, string> s_interval_translation;
    static const map<Const_HT_SINE_series_type, string> s_series_type_translation;
};

class MetaData_Type_HT_SINE
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string SeriesType;
    string TimeZone;

public:
    MetaData_Type_HT_SINE();
    MetaData_Type_HT_SINE(const MetaData_Type_HT_SINE& other); // copy constructor
    
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

class TechnicalIndicator_Type_HT_SINE
{
private:
    string SINE;
    string LEADSINE;
    string DateTime;

public:
    TechnicalIndicator_Type_HT_SINE();
    TechnicalIndicator_Type_HT_SINE(const TechnicalIndicator_Type_HT_SINE& other); // copy constructor

    string get_SINE() const {return SINE;};
    string get_LEADSINE() const {return LEADSINE;};
    string get_DateTime() const {return DateTime;};
    void set_SINE(string SINE){this->SINE = SINE;};
    void set_LEADSINE(string LEADSINE){this->LEADSINE = LEADSINE;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_HT_SINE_Content
{
private:
    MetaData_Type_HT_SINE MetaData;
    list<TechnicalIndicator_Type_HT_SINE> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_HT_SINE_Content();
    ~AvapiResponse_HT_SINE_Content() {};
    AvapiResponse_HT_SINE_Content(const AvapiResponse_HT_SINE_Content& other); // copy constructor
    MetaData_Type_HT_SINE& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_HT_SINE>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_HT_SINE
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_HT_SINE_Content* Data;

public:
    AvapiResponse_HT_SINE();
    AvapiResponse_HT_SINE(const AvapiResponse_HT_SINE& other); // copy constructor
    AvapiResponse_HT_SINE(AvapiResponse_HT_SINE&& other); // move constructor
    AvapiResponse_HT_SINE& operator=(const AvapiResponse_HT_SINE& other); //copy assignment
    AvapiResponse_HT_SINE& operator=(AvapiResponse_HT_SINE&& other); //move assignment
    ~AvapiResponse_HT_SINE();

    AvapiResponse_HT_SINE_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_HT_SINE
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_HT_SINE *s_instance;
    Impl_HT_SINE() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_HT_SINE& Response);

public:
    static Impl_HT_SINE& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_HT_SINE Query(string symbol
        ,Const_HT_SINE_interval interval
        ,Const_HT_SINE_series_type series_type
        );
        
    AvapiResponse_HT_SINE Query(string symbol
        ,string interval
        ,string series_type
        );
};

}//end namespace Avapi

#endif // HT_SINE_HPP_INCLUDED
