# AvapiCpp

AvapiCpp is a C++ API Wrapper allowing to retrieve data from Alpha Vantage endpoint (https://www.alphavantage.co/).  

To start using Avapi you just need to:
* Register to Alpha Vantage web site and get your personal api key (https://www.alphavantage.co/support/#api-key). It's for free!
* Configure your system
* Link the Avapi library on your project
* Enjoy :)



## Supported OS:
### Linux:
-Ubuntu 16

### Windows:
-_coming soon_



## Register to Alpha Vantage
To claim the Alpha Vantage free API key, you should register [here](https://www.alphavantage.co/support/#api-key) 



## Install Curl
To use Avapi you need to install the curl lib.

### Install curl for Ubuntu
```
$ sudo apt-get install libcurl4-openssl-dev
```



## Guided Example on how to consume Avapi library
There are a number of steps you need to follow to use Avapi:

### 1. Create an empty folder (e.g. AvapiExample)
```
$ mkdir /home/abcd/AvapiExample
```

### 2. Copy the Lib Folder (Avapi) in your folder:
```
$ cp -r Avapi /home/abcd/AvapiExample
```

### 3. Get in your folder and create a source file .cpp (e.g. AvapiExample.cpp): 
```
$ cd /home/abcd/AvapiExample
$ touch AvapiExample.cpp
```

### 4. Write your application in AvapiExample.cpp, below an example:
```
#include <string>
#include <iostream>
#include <sstream>
#include "Avapi/AvapiConnection.hpp"
#include "Avapi/TIME_SERIES/TIME_SERIES_DAILY.hpp"

using namespace std;
using namespace Avapi;

int main()
{
    string lastHttpRequest = "";
    AvapiConnection* avapi_connection;
    
    try
    {
        avapi_connection = AvapiConnection::getInstance();
        avapi_connection->set_ApiKey("Your Alpha Vantage API Key !!!!");
    }
    catch(AvapiConnectionError& e)
    {
        cout <<  e.get_error() << endl;
        return EXIT_FAILURE;
    }
    
    auto& QueryObject = avapi_connection->GetQueryObject_TIME_SERIES_DAILY();

    auto Response = QueryObject.Query(   
             "MSFT"
             ,Const_TIME_SERIES_DAILY_outputsize::compact
             ,Const_TIME_SERIES_DAILY_datatype::json);

    cout << endl <<  "******** RAW DATA TIME SERIES DAILY ********"<< endl;
    cout <<  Response.get_RawData() << endl << endl;

    cout << "******** STRUCTURED DATA TIME SERIES DAILY ********"<< endl;

    if(Response.get_Data().isError())
    {
        cerr << Response.get_Data().get_ErrorMessage() << endl;
    }
    else
    {
        auto& MetaData  = Response.get_Data().get_MetaData();
        auto& TimeSeries = Response.get_Data().get_TimeSeries();

        cout << "========================" << endl;
        cout << "Information: " <<  MetaData.get_Information() << endl;
        cout << "Symbol: " <<  MetaData.get_Symbol() << endl;
        cout << "LastRefreshed: " <<  MetaData.get_LastRefreshed() << endl;
        cout << "OutputSize: " <<  MetaData.get_OutputSize() << endl;
        cout << "TimeZone: " <<  MetaData.get_TimeZone() << endl;
        cout << "========================" << endl;
        cout << "========================" << endl;

        for(auto& element : TimeSeries)
        {
            cout << "Open: " << element.get_Open() << endl;
            cout << "High: " << element.get_High() << endl;
            cout << "Low: " << element.get_Low() << endl;
            cout << "Close: " << element.get_Close() << endl;
            cout << "Volume: " << element.get_Volume() << endl;
            cout << "DateTime: " << element.get_DateTime() << endl;
            cout << "========================" << endl;
        }
    }
    
	return EXIT_SUCCESS;
}
```
#### Remember:
- to replace the parameter in **avapi_connection->set_ApiKey("Your Alpha Vantage API Key !!!!")** , with your Alpha Vantage API key (to claim it see above).
- the library folder (Avapi/) has to be inside the AvapiExample, if you want to change the Avapi position you need to change these 2 lines in the code:
```
#include "DifferentAvapiPath/AvapiConnection.hpp"
#include "DifferentAvapiPath/TIME_SERIES/TIME_SERIES_DAILY.hpp" 
```

### 5. Run the following commands, to compile/configure and run your application: 

#### Linux:
```
$ g++  -L <LIB_PATH> -Wall -fexceptions -std=c++11 -g AvapiExample.cpp -o myExample -lavapi
$ export LD_LIBRARY_PATH=<LIB_PATH>:
$ ./myExample
```
you need to replace **<LIB_PATH>** with the Avapi path, in our example is: _/home/abcd/AvapiExample/Avapi/_. 

### 6. You can enjoy your _MSFT daily time series_ displayed on your shell :)
***

**Authors**: Antonio Papa and Simone Giuliani

**Email**: if you have any queries or suggestions please send us an email: sgiuliani.apapa at gmail.com
