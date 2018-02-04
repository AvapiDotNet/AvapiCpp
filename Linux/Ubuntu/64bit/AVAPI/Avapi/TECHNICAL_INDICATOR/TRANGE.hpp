#ifndef TRANGE_HPP_INCLUDED
#define TRANGE_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_TRANGE_interval{
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

class MAP_TRANGE
{
public:
    static const map<Const_TRANGE_interval, string> s_interval_translation;
};

class MetaData_Type_TRANGE
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string TimeZone;

public:
    MetaData_Type_TRANGE();
    MetaData_Type_TRANGE(const MetaData_Type_TRANGE& other); // copy constructor
    
    string get_Symbol() const {return Symbol;};
    string get_Indicator() const {return Indicator;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_Interval() const {return Interval;};
    string get_TimeZone() const {return TimeZone;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Indicator(string Indicator){this->Indicator = Indicator;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TechnicalIndicator_Type_TRANGE
{
private:
    string TRANGE;
    string DateTime;

public:
    TechnicalIndicator_Type_TRANGE();
    TechnicalIndicator_Type_TRANGE(const TechnicalIndicator_Type_TRANGE& other); // copy constructor

    string get_TRANGE() const {return TRANGE;};
    string get_DateTime() const {return DateTime;};
    void set_TRANGE(string TRANGE){this->TRANGE = TRANGE;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_TRANGE_Content
{
private:
    MetaData_Type_TRANGE MetaData;
    list<TechnicalIndicator_Type_TRANGE> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_TRANGE_Content();
    ~AvapiResponse_TRANGE_Content() {};
    AvapiResponse_TRANGE_Content(const AvapiResponse_TRANGE_Content& other); // copy constructor
    MetaData_Type_TRANGE& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_TRANGE>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_TRANGE
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_TRANGE_Content* Data;

public:
    AvapiResponse_TRANGE();
    AvapiResponse_TRANGE(const AvapiResponse_TRANGE& other); // copy constructor
    AvapiResponse_TRANGE(AvapiResponse_TRANGE&& other); // move constructor
    AvapiResponse_TRANGE& operator=(const AvapiResponse_TRANGE& other); //copy assignment
    AvapiResponse_TRANGE& operator=(AvapiResponse_TRANGE&& other); //move assignment
    ~AvapiResponse_TRANGE();

    AvapiResponse_TRANGE_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_TRANGE
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_TRANGE *s_instance;
    Impl_TRANGE() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_TRANGE& Response);

public:
    static Impl_TRANGE& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_TRANGE Query(string symbol
        ,Const_TRANGE_interval interval
        );
        
    AvapiResponse_TRANGE Query(string symbol
        ,string interval
        );
};

}//end namespace Avapi

#endif // TRANGE_HPP_INCLUDED
