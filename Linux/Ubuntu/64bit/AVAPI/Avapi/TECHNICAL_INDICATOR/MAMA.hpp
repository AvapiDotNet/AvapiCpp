#ifndef MAMA_HPP_INCLUDED
#define MAMA_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_MAMA_interval{
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

enum class Const_MAMA_series_type{
    none,
    close,
    open,
    high,
    low,
};

class MAP_MAMA
{
public:
    static const map<Const_MAMA_interval, string> s_interval_translation;
    static const map<Const_MAMA_series_type, string> s_series_type_translation;
};

class MetaData_Type_MAMA
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string FastLimit;
    string SlowLimit;
    string SeriesType;
    string TimeZone;

public:
    MetaData_Type_MAMA();
    MetaData_Type_MAMA(const MetaData_Type_MAMA& other); // copy constructor
    
    string get_Symbol() const {return Symbol;};
    string get_Indicator() const {return Indicator;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_Interval() const {return Interval;};
    string get_FastLimit() const {return FastLimit;};
    string get_SlowLimit() const {return SlowLimit;};
    string get_SeriesType() const {return SeriesType;};
    string get_TimeZone() const {return TimeZone;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Indicator(string Indicator){this->Indicator = Indicator;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_FastLimit(string FastLimit){this->FastLimit = FastLimit;};
    void set_SlowLimit(string SlowLimit){this->SlowLimit = SlowLimit;};
    void set_SeriesType(string SeriesType){this->SeriesType = SeriesType;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TechnicalIndicator_Type_MAMA
{
private:
    string FAMA;
    string MAMA;
    string DateTime;

public:
    TechnicalIndicator_Type_MAMA();
    TechnicalIndicator_Type_MAMA(const TechnicalIndicator_Type_MAMA& other); // copy constructor

    string get_FAMA() const {return FAMA;};
    string get_MAMA() const {return MAMA;};
    string get_DateTime() const {return DateTime;};
    void set_FAMA(string FAMA){this->FAMA = FAMA;};
    void set_MAMA(string MAMA){this->MAMA = MAMA;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_MAMA_Content
{
private:
    MetaData_Type_MAMA MetaData;
    list<TechnicalIndicator_Type_MAMA> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_MAMA_Content();
    ~AvapiResponse_MAMA_Content() {};
    AvapiResponse_MAMA_Content(const AvapiResponse_MAMA_Content& other); // copy constructor
    MetaData_Type_MAMA& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_MAMA>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_MAMA
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_MAMA_Content* Data;

public:
    AvapiResponse_MAMA();
    AvapiResponse_MAMA(const AvapiResponse_MAMA& other); // copy constructor
    AvapiResponse_MAMA(AvapiResponse_MAMA&& other); // move constructor
    AvapiResponse_MAMA& operator=(const AvapiResponse_MAMA& other); //copy assignment
    AvapiResponse_MAMA& operator=(AvapiResponse_MAMA&& other); //move assignment
    ~AvapiResponse_MAMA();

    AvapiResponse_MAMA_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_MAMA
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_MAMA *s_instance;
    Impl_MAMA() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_MAMA& Response);

public:
    static Impl_MAMA& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_MAMA Query(string symbol
        ,Const_MAMA_interval interval
        ,Const_MAMA_series_type series_type
        ,string fastlimit
        ,string slowlimit
        );
        
    AvapiResponse_MAMA Query(string symbol
        ,string interval
        ,string series_type
        ,string fastlimit
        ,string slowlimit
        );
};

}//end namespace Avapi

#endif // MAMA_HPP_INCLUDED
