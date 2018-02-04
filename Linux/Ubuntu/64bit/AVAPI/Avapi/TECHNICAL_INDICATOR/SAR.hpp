#ifndef SAR_HPP_INCLUDED
#define SAR_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_SAR_interval{
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

class MAP_SAR
{
public:
    static const map<Const_SAR_interval, string> s_interval_translation;
};

class MetaData_Type_SAR
{
private:
    string Symbol;
    string Indicator;
    string LastRefreshed;
    string Interval;
    string Acceleration;
    string Maximum;
    string TimeZone;

public:
    MetaData_Type_SAR();
    MetaData_Type_SAR(const MetaData_Type_SAR& other); // copy constructor
    
    string get_Symbol() const {return Symbol;};
    string get_Indicator() const {return Indicator;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_Interval() const {return Interval;};
    string get_Acceleration() const {return Acceleration;};
    string get_Maximum() const {return Maximum;};
    string get_TimeZone() const {return TimeZone;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Indicator(string Indicator){this->Indicator = Indicator;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_Interval(string Interval){this->Interval = Interval;};
    void set_Acceleration(string Acceleration){this->Acceleration = Acceleration;};
    void set_Maximum(string Maximum){this->Maximum = Maximum;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TechnicalIndicator_Type_SAR
{
private:
    string SAR;
    string DateTime;

public:
    TechnicalIndicator_Type_SAR();
    TechnicalIndicator_Type_SAR(const TechnicalIndicator_Type_SAR& other); // copy constructor

    string get_SAR() const {return SAR;};
    string get_DateTime() const {return DateTime;};
    void set_SAR(string SAR){this->SAR = SAR;};
    void set_DateTime(string DateTime){this->DateTime = DateTime;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_SAR_Content
{
private:
    MetaData_Type_SAR MetaData;
    list<TechnicalIndicator_Type_SAR> TechnicalIndicator;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_SAR_Content();
    ~AvapiResponse_SAR_Content() {};
    AvapiResponse_SAR_Content(const AvapiResponse_SAR_Content& other); // copy constructor
    MetaData_Type_SAR& get_MetaData() {return MetaData;};
    list<TechnicalIndicator_Type_SAR>& get_TechnicalIndicator() {return TechnicalIndicator;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_SAR
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_SAR_Content* Data;

public:
    AvapiResponse_SAR();
    AvapiResponse_SAR(const AvapiResponse_SAR& other); // copy constructor
    AvapiResponse_SAR(AvapiResponse_SAR&& other); // move constructor
    AvapiResponse_SAR& operator=(const AvapiResponse_SAR& other); //copy assignment
    AvapiResponse_SAR& operator=(AvapiResponse_SAR&& other); //move assignment
    ~AvapiResponse_SAR();

    AvapiResponse_SAR_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_SAR
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_SAR *s_instance;
    Impl_SAR() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_SAR& Response);

public:
    static Impl_SAR& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_SAR Query(string symbol
        ,Const_SAR_interval interval
        ,string acceleration
        ,string maximum
        );
        
    AvapiResponse_SAR Query(string symbol
        ,string interval
        ,string acceleration
        ,string maximum
        );
};

}//end namespace Avapi

#endif // SAR_HPP_INCLUDED
