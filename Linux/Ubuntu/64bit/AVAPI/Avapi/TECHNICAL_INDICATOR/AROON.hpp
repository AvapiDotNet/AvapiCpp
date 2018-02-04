#ifndef AROON_HPP_INCLUDED
#define AROON_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_AROON_interval{
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

class MAP_AROON
{
public:
    static const map<Const_AROON_interval, string> s_interval_translation;
};

class MetaData_Type_AROON
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string TimePeriod;
    string TimeZone;

public:
    MetaData_Type_AROON();
    MetaData_Type_AROON(const MetaData_Type_AROON& other); // copy constructor
    
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

class TechnicalIndicator_Type_AROON
{
private:
    string AroonDown;
    string AroonUp;
    string DateTime;

public:
    TechnicalIndicator_Type_AROON();
    TechnicalIndicator_Type_AROON(const TechnicalIndicator_Type_AROON& other); // copy constructor

    string get_AroonDown() const {return AroonDown;};
    string get_AroonUp() const {return AroonUp;};
    string get_DateTime() const {return DateTime;};
    void set_AroonDown(string AroonDown){this->AroonDown = AroonDown;};
    void set_AroonUp(string AroonUp){this->AroonUp = AroonUp;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_AROON_Content
{
private:
    MetaData_Type_AROON MetaData;
    list<TechnicalIndicator_Type_AROON> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_AROON_Content();
    ~AvapiResponse_AROON_Content() {};
    AvapiResponse_AROON_Content(const AvapiResponse_AROON_Content& other); // copy constructor
    MetaData_Type_AROON& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_AROON>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_AROON
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_AROON_Content* Data;

public:
    AvapiResponse_AROON();
    AvapiResponse_AROON(const AvapiResponse_AROON& other); // copy constructor
    AvapiResponse_AROON(AvapiResponse_AROON&& other); // move constructor
    AvapiResponse_AROON& operator=(const AvapiResponse_AROON& other); //copy assignment
    AvapiResponse_AROON& operator=(AvapiResponse_AROON&& other); //move assignment
    ~AvapiResponse_AROON();

    AvapiResponse_AROON_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_AROON
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_AROON *s_instance;
    Impl_AROON() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_AROON& Response);

public:
    static Impl_AROON& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_AROON Query(string symbol
        ,Const_AROON_interval interval
        ,string time_period
        );
        
    AvapiResponse_AROON Query(string symbol
        ,string interval
        ,string time_period
        );
};

}//end namespace Avapi

#endif // AROON_HPP_INCLUDED
