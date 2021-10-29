#include "Recognizer.h"
#include "Gen.h"


int main(int argc, char* argv[]) {
    int retcode = 0;
    std::string str;
    if (argc < 2)
    {
        std::cerr << "No file to check." << std::endl;
        retcode = 2;
    }
    else if (argc > 3)
    {
        std::cerr << "Only two arguments accepted." << std::endl;
        retcode = 3;
    }
    else if (argc == 3 && std::string(argv[2]) != "TIMING") {
        std::cerr << "Wrong flag." << std::endl;
        retcode = 3;
    }
    else
    {
        Recognizer thisContext(argv[1]);
        std::ifstream file(argv[1]);
        if (file.is_open()) {
            if (argc == 2) {
                while (!file.eof()) {
                    std::getline(file, str);
                    try {
                        thisContext.run(str);
                    }
                    catch (std::runtime_error&) {
                        retcode = 1;
                    }
                }
                std::string of(argv[1]);
                thisContext.fix_result();
                thisContext.write();
            }
            else {
                long long count = 0;
                while (!file.eof()) {
                    count++;
                    std::getline(file, str);
                    std::cout << count << std::endl;
                    try {
                        thisContext.timing(str);
                    }
                    catch (std::runtime_error&) {
                        retcode = 1;
                    }
                }
                std::cout << count << " strings checked in " << thisContext.showTime().count() << " ns" << std::endl;
            }
        }
        else
            std::cerr << "Error: can't open the file" << std::endl;
    }
    return retcode;


    //std::string timingF("Output.txt");
    //std::ofstream of(timingF);
    //for (int strings = 10; strings <= 1000;) {
    //        for (int len = 50; len <= 100000;) {
    //            std::string filename("Timing_" + std::to_string(strings) + "_" + std::to_string(len) + ".txt");
    //            std::ifstream istr(filename);
    //            Recognizer thisContext(filename);
    //            long long count = 0;
    //                while (!istr.eof()) {
    //                    count++;
    //                    std::getline(istr, str);
    //                    try {
    //                        thisContext.timing(str);
    //                    }
    //                    catch (std::runtime_error&) {
    //                        retcode = 1;
    //                    }
    //                }
    //                std::cout << filename << " END " << std::endl;
    //            of << "REGEX  " << count << " strings, length" << len << " checked in " << thisContext.showTime().count() << " ns" << std::endl;
    //            switch (len)
    //            {
    //            case 50: {len = 200; break; }
    //            case 200: {len = 500; break; }
    //            case 500: {len = 1000; break; }
    //            case 1000: {len = 10000; break; }
    //            case 10000: {len = 100000; break; }
    //            default:
    //                len += 1;
    //            }
    //        }
    //        switch (strings)
    //        {
    //        case 10: {strings = 50; break; }
    //        case 50: {strings = 200; break; }
    //        case 200: {strings = 500; break; }
    //        case 500: {strings = 1000; break; }
    //        default:
    //            strings += 1;
    //        }
    //    }


    //for (int strings = 10; strings <= 100000;) {
    //    for (int len = 50; len <= 100000;) {
    //        std::string filename("Timing_" + std::to_string(strings) + "_" + std::to_string(len) + ".txt");
    //        std::ofstream ostr(filename);
    //        for (int i = 0; i < strings; i++) {
    //            if (rand() % 2)
    //                ostr << generateCorrectS(len) << std::endl;
    //            else
    //                ostr << generateWrongS(len) << std::endl;
    //        }
    //        switch (len)
    //        {
    //        case 50: {len = 200; break; }
    //        case 200: {len = 500; break; }
    //        case 500: {len = 1000; break; }
    //        case 1000: {len = 10000; break; }
    //        case 10000: {len = 100000; break; }
    //        default:
    //            len += 1;
    //        }
    //    }
    //    switch (strings)
    //    {
    //    case 10: {strings = 50; break; }
    //    case 50: {strings = 200; break; }
    //    case 200: {strings = 500; break; }
    //    case 500: {strings = 1000; break; }
    //    default:
    //        strings += 1;
    //    }
    //}
}