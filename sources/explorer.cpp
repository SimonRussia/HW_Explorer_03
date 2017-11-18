#include <explorer.hpp>

// name
void f1(const path& _path) {
    std::ofstream out( "log.txt", std::ios_base::app);
    out << "\tname:\t" << _path.filename() << std::endl;
    out.close();
}
// size
void f2(const path& _path) {
    std::ofstream out( "log.txt", std::ios_base::app);
    out << "\tsize:\t" << ( ( (double)(file_size(_path) ) ) / 1000 ) << std::endl;
    out.close();
}
// date
void f3(const path& _path) {
    std::time_t cftime = last_write_time(_path);
    std::ofstream out( "log.txt", std::ios_base::app);
    out << "\tdate:\t" << asctime(localtime(&cftime)) << std::endl;
    out.close();
}

bool print_info(const path& _path) {
    if(!exists(_path) )
        return false;

    f1(_path);
    f2(_path);
    f3(_path);

    return true;
}


int main(int argc, char const *argv[]) {
    try {
        std::ofstream out( "log.txt", std::ios_base::app);
        out << std::endl << "SESSION OF RECORDING INTO LOG.TXT:\t" << to_simple_string(second_clock::local_time()) << std::endl << std::endl;
        out.close();

        std::string address = "explorer/";
        scheduler_t scheduler;

        // std::vector<std::future<bool> > results;
        // std::vector<std::future<bool> >::iterator iter_results;

        std::map<const path, std::future<bool> > results;

        for (int i = 1; i < argc; i++) {

            const path p = address + argv[i];

            auto task = std::packaged_task<bool()> { std::bind(print_info, p) };
            auto result = task.get_future();

            scheduler.add( task );

            results.emplace(p, std::move(result));

            // results.push_back( std::move(result) );
        }

        scheduler.run(); // run in a new thred

        // for(iter_results = results.begin(); iter_results != results.end(); iter_results++) {
        //     if(iter_results->get() == false) {
        //         std::cerr << "BAD LINK!!!" << std::endl;
        //     }
        // }

        for(auto & p : results) {
            auto& result = p.second;
            auto is_ok = result.get();
            if (! is_ok) {
                std::cerr << "\tBAD LINK:\t" << p.first << std::endl;
            }
        }


    }  catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
