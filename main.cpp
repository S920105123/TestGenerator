#include "timer.h"
using namespace std;


int main(int argc, char** argv)
{
 if(argc<3){
	 cout << "no enough arguments.\n" << std::endl;
	 my_exit();
 }
	Timer timer;
 	timer.gen_test(argv[1], argv[2]);
}

// int main(int argc, char **argv){
// 
//     if (argc == 5) {
//         // Contest format
//         // timer.gen_test(argv[1], argv[2], argv[3], argv[4]);
//     }
//     else if(argc>1) {
//         // Generate testcase
//         string testcase = argv[1];
//         string timer_argv[10];
//         timer_argv[1] = "./benchmark/testcases/" + testcase + "/" + testcase + ".tau2015";
//         timer_argv[2] = "./benchmark/testcases/" + testcase + "/" + testcase + ".ops";
//         timer_argv[3] = argv[2];
//         Timer timer;
//         cout << " --- Timer gen " << testcase << " testcase ---" << endl;
//         timer.gen_test(timer_argv[3], timer_argv[1], timer_argv[2]);
//     }
//     else {
//         // Testing
//         string testcase, timer_argv[10];
//         cout << "enter testcase(c17/simple...): ";
//         cin >> testcase;
//         timer_argv[1] = "./benchmark/testcases/" + testcase + "/" + testcase + ".tau2018";
//         timer_argv[2] = "./benchmark/testcases/" + testcase + "/" + testcase + ".timing";
//         timer_argv[3] = "./benchmark/testcases/" + testcase + "/" + testcase + ".ops";
//         timer_argv[4] = "./benchmark/testcases/" + testcase + "/" + testcase + ".myoutput";
//         Timer timer;
//         timer.run(string(timer_argv[1]), string(timer_argv[2]), string(timer_argv[3]), string(timer_argv[4]));
//     }
//     // cout << "myoutput is under ./benchmark/testcases/" << testcase << endl;
// }
