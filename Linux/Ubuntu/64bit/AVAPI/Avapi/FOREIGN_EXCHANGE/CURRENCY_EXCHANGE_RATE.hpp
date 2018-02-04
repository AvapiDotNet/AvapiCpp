#ifndef CURRENCY_EXCHANGE_RATE_HPP_INCLUDED
#define CURRENCY_EXCHANGE_RATE_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

class MetaData_Type_CURRENCY_EXCHANGE_RATE
{
private:

public:
    MetaData_Type_CURRENCY_EXCHANGE_RATE();
    MetaData_Type_CURRENCY_EXCHANGE_RATE(const MetaData_Type_CURRENCY_EXCHANGE_RATE& other); // copy constructor

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class CERate_Type_CURRENCY_EXCHANGE_RATE
{
private:
    string FromCurrencyCode;
    string FromCurrencyName;
    string ToCurrencyCode;
    string ToCurrencyName;
    string ExchangeRate;
    string LastRefreshed;
    string TimeZone;

public:
    CERate_Type_CURRENCY_EXCHANGE_RATE();
    CERate_Type_CURRENCY_EXCHANGE_RATE(const CERate_Type_CURRENCY_EXCHANGE_RATE& other); // copy constructor

    string get_FromCurrencyCode() const {return FromCurrencyCode;};
    string get_FromCurrencyName() const {return FromCurrencyName;};
    string get_ToCurrencyCode() const {return ToCurrencyCode;};
    string get_ToCurrencyName() const {return ToCurrencyName;};
    string get_ExchangeRate() const {return ExchangeRate;};
    string get_LastRefreshed() const {return LastRefreshed;};
    string get_TimeZone() const {return TimeZone;};
    void set_FromCurrencyCode(string FromCurrencyCode){this->FromCurrencyCode = FromCurrencyCode;};
    void set_FromCurrencyName(string FromCurrencyName){this->FromCurrencyName = FromCurrencyName;};
    void set_ToCurrencyCode(string ToCurrencyCode){this->ToCurrencyCode = ToCurrencyCode;};
    void set_ToCurrencyName(string ToCurrencyName){this->ToCurrencyName = ToCurrencyName;};
    void set_ExchangeRate(string ExchangeRate){this->ExchangeRate = ExchangeRate;};
    void set_LastRefreshed(string LastRefreshed){this->LastRefreshed = LastRefreshed;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_CURRENCY_EXCHANGE_RATE_Content
{
private:
    MetaData_Type_CURRENCY_EXCHANGE_RATE MetaData;
    list<CERate_Type_CURRENCY_EXCHANGE_RATE> CERate;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_CURRENCY_EXCHANGE_RATE_Content();
    ~AvapiResponse_CURRENCY_EXCHANGE_RATE_Content() {};
    AvapiResponse_CURRENCY_EXCHANGE_RATE_Content(const AvapiResponse_CURRENCY_EXCHANGE_RATE_Content& other); // copy constructor
    MetaData_Type_CURRENCY_EXCHANGE_RATE& get_MetaData() {return MetaData;};
    list<CERate_Type_CURRENCY_EXCHANGE_RATE>& get_CERate() {return CERate;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_CURRENCY_EXCHANGE_RATE
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_CURRENCY_EXCHANGE_RATE_Content* Data;

public:
    AvapiResponse_CURRENCY_EXCHANGE_RATE();
    AvapiResponse_CURRENCY_EXCHANGE_RATE(const AvapiResponse_CURRENCY_EXCHANGE_RATE& other); // copy constructor
    AvapiResponse_CURRENCY_EXCHANGE_RATE(AvapiResponse_CURRENCY_EXCHANGE_RATE&& other); // move constructor
    AvapiResponse_CURRENCY_EXCHANGE_RATE& operator=(const AvapiResponse_CURRENCY_EXCHANGE_RATE& other); //copy assignment
    AvapiResponse_CURRENCY_EXCHANGE_RATE& operator=(AvapiResponse_CURRENCY_EXCHANGE_RATE&& other); //move assignment
    ~AvapiResponse_CURRENCY_EXCHANGE_RATE();

    AvapiResponse_CURRENCY_EXCHANGE_RATE_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_CURRENCY_EXCHANGE_RATE
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_CURRENCY_EXCHANGE_RATE *s_instance;
    Impl_CURRENCY_EXCHANGE_RATE() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_CURRENCY_EXCHANGE_RATE& Response);

public:
    static Impl_CURRENCY_EXCHANGE_RATE& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_CURRENCY_EXCHANGE_RATE Query(string from_currency,
            string to_currency);
};

}//end namespace Avapi

#endif // CURRENCY_EXCHANGE_RATE_HPP_INCLUDED
