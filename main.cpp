#include <iostream>
#include "cpr/cpr.h"

enum Command
{
    GET,
    POST,
    PUT,
    DELETE,
    PATCH,
    EXIT
};

/**
 * @function Get one of the commands (get, post, patch, delete, put) from cin input.
 * Returns the Command or error message.
 * @return Command
 */
Command getCommand()
{
    while (true)
    {
        std::cout << "Please enter the command: ";
        std::string buffer;
        std::getline(std::cin, buffer);
        if (buffer == "get")
            return GET;
        else if (buffer == "post")
            return POST;
        else if (buffer == "put")
            return PUT;
        else if (buffer == "delete")
            return DELETE;
        else if (buffer == "patch")
            return PATCH;
        else if (buffer == "ext")
            return EXIT;
        else
            std::cerr << "Unknown command. Try again.\n";
    }
}

int main() {
    bool isOngoing = true;
    while (isOngoing)
    {
        Command cmd = getCommand();
        cpr::Response r;
        switch (cmd)
        {
            case GET:
                r = cpr::Get(cpr::Url("http://httpbin.org/get"));
                break;
            case POST:
                r = cpr::Post(cpr::Url("http://httpbin.org/post"));
                break;
            case PUT:
                r = cpr::Put(cpr::Url("http://httpbin.org/put"));
                break;
            case DELETE:
                r = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
                break;
            case PATCH:
                r = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
                break;
            case EXIT:
                r.text = "Exiting the program...\n";
                isOngoing = false;
                break;
        }
        std::cout << r.text << "\n";
    }

    std::cout << "Program is finished.\n";
    return 0;
}