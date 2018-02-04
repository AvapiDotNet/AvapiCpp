#ifndef BOP_HPP_INCLUDED
#define BOP_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_BOP_interval{
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

class MAP_BOP
{
public:
    static const map<Const_BOP_interval, string> s_interval_translation;
};

class MetaData_Type_BOP
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string TimeZone;

public:
    MetaData_Type_BOP();
    MetaData_Type_BOP(const MetaData_Type_BOP& other); // copy constructor
    
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

class TechnicalIndicator_Type_BOP
{
private:
    string BOP;
    string DateTime;

public:
    TechnicalIndicator_Type_BOP();
    TechnicalIndicator_Type_BOP(const TechnicalIndicator_Type_BOP& other); // copy constructor

    string get_BOP() const {return BOP;};
    string get_DateTime() const {return DateTime;};
    void set_BOP(string BOP){this->BOP = BOP;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_BOP_Content
{
private:
    MetaData_Type_BOP MetaData;
    list<TechnicalIndicator_Type_BOP> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_BOP_Content();
    ~AvapiResponse_BOP_Content() {};
    AvapiResponse_BOP_Content(const AvapiResponse_BOP_Content& other); // copy constructor
    MetaData_Type_BOP& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_BOP>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_BOP
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_BOP_Content* Data;

public:
    AvapiResponse_BOP();
    AvapiResponse_BOP(const AvapiResponse_BOP& other); // copy constructor
    AvapiResponse_BOP(AvapiResponse_BOP&& other); // move constructor
    AvapiResponse_BOP& operator=(const AvapiResponse_BOP& other); //copy assignment
    AvapiResponse_BOP& operator=(AvapiResponse_BOP&& other); //move assignment
    ~AvapiResponse_BOP();

    AvapiResponse_BOP_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_BOP
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_BOP *s_instance;
    Impl_BOP() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_BOP& Response);

public:
    static Impl_BOP& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_BOP Query(string symbol
        ,Const_BOP_interval interval
        );
        
    AvapiResponse_BOP Query(string symbol
        ,string interval
        );
};

}//end namespace Avapi

#endif // BOP_HPP_INCLUDED
