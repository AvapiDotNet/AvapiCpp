#ifndef BATCH_STOCK_QUOTES_HPP_INCLUDED
#define BATCH_STOCK_QUOTES_HPP_INCLUDED

#include <string>
#include <map>
#include <list>
#include "../jsmn/jsmn.h"

using namespace std;

namespace Avapi {

class RestClient; //forward declaration

enum class Const_BATCH_STOCK_QUOTES_datatype{
    none,
    json,
    csv,
};

class MAP_BATCH_STOCK_QUOTES
{
public:
    static const map<Const_BATCH_STOCK_QUOTES_datatype, string> s_datatype_translation;
};

class MetaData_Type_BATCH_STOCK_QUOTES
{
private:
    string Information;
    string Notes;
    string TimeZone;

public:
    MetaData_Type_BATCH_STOCK_QUOTES();
    MetaData_Type_BATCH_STOCK_QUOTES(const MetaData_Type_BATCH_STOCK_QUOTES& other); // copy constructor
    
    string get_Information() const {return Information;};
    string get_Notes() const {return Notes;};
    string get_TimeZone() const {return TimeZone;};
    void set_Information(string Information){this->Information = Information;};
    void set_Notes(string Notes){this->Notes = Notes;};
    void set_TimeZone(string TimeZone){this->TimeZone = TimeZone;};

    int ParseInternal(string& str_data, jsmntok_t* array_token ,int index, int token_size);
};

class TimeSeries_Type_BATCH_STOCK_QUOTES
{
private:
    string Symbol;
    string Price;
    string Volume;
    string TimeStamp;

public:
    TimeSeries_Type_BATCH_STOCK_QUOTES();
    TimeSeries_Type_BATCH_STOCK_QUOTES(const TimeSeries_Type_BATCH_STOCK_QUOTES& other); // copy constructor

    string get_Symbol() const {return Symbol;};
    string get_Price() const {return Price;};
    string get_Volume() const {return Volume;};
    string get_TimeStamp() const {return TimeStamp;};
    void set_Symbol(string Symbol){this->Symbol = Symbol;};
    void set_Price(string Price){this->Price = Price;};
    void set_Volume(string Volume){this->Volume = Volume;};
    void set_TimeStamp(string TimeStamp){this->TimeStamp = TimeStamp;};
    
   int ParseInternal(string& str_data, jsmntok_t* array_token, int index, int token_size);
};

class AvapiResponse_BATCH_STOCK_QUOTES_Content
{
private:
    MetaData_Type_BATCH_STOCK_QUOTES MetaData;
    list<TimeSeries_Type_BATCH_STOCK_QUOTES> TimeSeries;
    string str_prefix;
    bool error_status;
    string ErrorMessage;

public:
    AvapiResponse_BATCH_STOCK_QUOTES_Content();
    ~AvapiResponse_BATCH_STOCK_QUOTES_Content() {};
    AvapiResponse_BATCH_STOCK_QUOTES_Content(const AvapiResponse_BATCH_STOCK_QUOTES_Content& other); // copy constructor
    MetaData_Type_BATCH_STOCK_QUOTES& get_MetaData() {return MetaData;};
    list<TimeSeries_Type_BATCH_STOCK_QUOTES>& get_TimeSeries() {return TimeSeries;};
    void set_Error(bool error_status) {this->error_status = error_status;};
    bool isError() {return error_status;};
    string get_ErrorMessage() {return ErrorMessage;};
    void set_ErrorMessage(string ErrorMessage) {this->ErrorMessage = str_prefix + ErrorMessage;};
};

class AvapiResponse_BATCH_STOCK_QUOTES
{
private:
    string LastHttpRequest;
    string RawData;
    AvapiResponse_BATCH_STOCK_QUOTES_Content* Data;

public:
    AvapiResponse_BATCH_STOCK_QUOTES();
    AvapiResponse_BATCH_STOCK_QUOTES(const AvapiResponse_BATCH_STOCK_QUOTES& other); // copy constructor
    AvapiResponse_BATCH_STOCK_QUOTES(AvapiResponse_BATCH_STOCK_QUOTES&& other); // move constructor
    AvapiResponse_BATCH_STOCK_QUOTES& operator=(const AvapiResponse_BATCH_STOCK_QUOTES& other); //copy assignment
    AvapiResponse_BATCH_STOCK_QUOTES& operator=(AvapiResponse_BATCH_STOCK_QUOTES&& other); //move assignment
    ~AvapiResponse_BATCH_STOCK_QUOTES();

    AvapiResponse_BATCH_STOCK_QUOTES_Content& get_Data() const {return *Data;};
    string get_LastHttpRequest() const {return LastHttpRequest;};
    string get_RawData() const {return RawData;};
    void set_LastHttpRequest(string LastHttpRequest){this->LastHttpRequest = LastHttpRequest;};
    void set_RawData(string RawData){this->RawData = RawData;};
};

class Impl_BATCH_STOCK_QUOTES
{
private:
    string AvapiUrl;
    string ApiKey;
    RestClient *Client;
    static string s_function;
    static Impl_BATCH_STOCK_QUOTES *s_instance;
    Impl_BATCH_STOCK_QUOTES() {};
    static const unsigned int START_TOKEN_SIZE = 3000;
    static void ParseInternal(AvapiResponse_BATCH_STOCK_QUOTES& Response);

public:
    static Impl_BATCH_STOCK_QUOTES& getInstance();
    static void destroyInstance();

    string get_AvapiUrl() const {return AvapiUrl;};
    RestClient* get_Client() const {return Client;};
    string get_ApiKey() const {return ApiKey;};
    void set_AvapiUrl(string AvapiUrl){this->AvapiUrl = AvapiUrl;};
    void set_Client(RestClient *Client){this->Client = Client;};
    void set_ApiKey(string ApiKey){this->ApiKey = ApiKey;};

    AvapiResponse_BATCH_STOCK_QUOTES Query(string symbols
        ,Const_BATCH_STOCK_QUOTES_datatype datatype  = Const_BATCH_STOCK_QUOTES_datatype::none
        );

    AvapiResponse_BATCH_STOCK_QUOTES Query(string symbols
        ,string datatype  = "json"
        );
};

}//end namespace Avapi

#endif // BATCH_STOCK_QUOTES_HPP_INCLUDED
