```
  _______                                   __   _____                       ______                           __               
 /_  __(_)___ ___  ___     ____ _____  ____/ /  /__  /  ____  ____  ___     / ____/___  ____ _   _____  _____/ /____  _____    
  / / / / __ `__ \/ _ \   / __ `/ __ \/ __  /     / /  / __ \/ __ \/ _ \   / /   / __ \/ __ \ | / / _ \/ ___/ __/ _ \/ ___/    
 / / / / / / / / /  __/  / /_/ / / / / /_/ /     / /__/ /_/ / / / /  __/  / /___/ /_/ / / / / |/ /  __/ /  / /_/  __/ /        
/_/ /_/_/ /_/ /_/\___/   \__,_/_/ /_/\__,_/     /____/\____/_/ /_/\___/   \____/\____/_/ /_/|___/\___/_/   \__/\___/_/         
                                                                                                                               
```
# solid-time-and-zone-converter
Implement a simple converter allowing time convertion from GMT (Greenwich Mean) to  PDT (Pacific Daylight Time (North America)) and vice-versa. Converter should be implemented  in a way that allows extending it easily when adding new time zones.
___
## Author:
Michał Loska

___
## How to Run:

### Compile:
>make

### Compile and/or Run (WITH CMAKE) </br>

```
1. mkdir build
2. cd build
3. cmake ..
```
compile:
> make

run UT tests:
> make test 
or:
> ctest

the above solution will not display failing tests if any occur. Please use <b> make run_tests </b> instead:

### Compile and/or Run: </br>
Due to the fact a project like this requires using Makefile the program has to be run a bitt differently to what was written in documize:

>make run TIME=(time_to_be_converted) SRCT=(source_time_zone) DESTT=(destination_time_zone) 

eg.:
```
make run TIME=11:00 SRCT=PDT DESTT=GMT
OUTPUT:
./Executable 11:00 PDT GMT
Converting 11:00 PDT(UTC-8:00) to GMT(UTC+0:00)
Outcome Time:19:00

OR:

make run TIME=11 SRCT=PDT DESTT=GMT
OUTPUT:
./Executable 11:00 PDT GMT
Converting 11:00 PDT(UTC-8:00) to GMT(UTC+0:00)
Outcome Time:19:00
```

Supported TimeZones:
* PDT UTC-8:0 
* GMT UTC+0:0
* IRST UTC+3:30 (IRANIAN TIME ZONE)


Implemented Time Zones are present in the TimeZoneConverterUtils.hpp file. More can be there.
If timezone is not supported a suitable output will be displayed

### Clean:
>make clean

### Run UT tests:
>make test

Remark: in order to run UT tests Google Test has to be installed.

1. Clone the Google Test repo one catalogue above this project's repo
>git clone https://github.com/google/googletest ..

2. Go to the downloaded repo and create build directory
> cd .. googletest-master && mkdir build

3. Enter the folder and execute cmake
> cd build && cmake ..

4. Compile
> make

5. Copy Header files to the project directory
Copy gtest folder from googletest/include/gtest to solid-time-and-zone-converter-task/tests
> cp -r googletest-master/googletest/include/gtest solid-time-and-zone-converter-task/tests

6. Done!

Path to google test library is already specified in Makefile in GTEST variable
