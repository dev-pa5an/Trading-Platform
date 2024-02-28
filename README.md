# Trading-Platform

In the CSV file, the orderType can vary between "bid" and "ask" only. To constrain that, we can define an enum within a namespace.

The best practice is not to define the enum class in the main function but to add it as a header file.

Since we have a lot of data to analyze, we need a data structure to access these data, introducing vectors.

Let's organize the OrderBookEntry class with separate header and implementation files, OrderBookEntry.h and OrderBookEntry.cpp.

We will also refactor the functions in merkelMain.h and merkelMain.cpp to improve encapsulation.
