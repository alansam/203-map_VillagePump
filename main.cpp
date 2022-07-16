/*
 *  Hello 
 *  I'm trying to work my search map algorithm 
 *  But it's doesn't give me true answer 
 *  Any can check 
 */

// /////////////////////////////////////////////////////////////////////// //
//                           my c++ map                                    //
//                     i'm trying to create my own map                     //
// /////////////////////////////////////////////////////////////////////// //      

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

#include "Village.hpp"

int main(int argc, char const * argv[]) {
  std::cout << "FarOnerlookedArchive"
            << std::endl;

  auto villages = std::vector<Village> {
    { "C1", "P1", "D1", "S1", "L1", "V1", },
    { "C1", "P1", "D1", "S1", "L1", "V2", },
    { "C2", "P1", "D1", "S1", "L1", "V1", },
  };

  villages.push_back({ "C2", "P1", "D1", "S2", "L1", "V3", });

  {
    auto vt = Village("C1", "P1", "D3", "S1", "L1", "V1");
    std::clog << ".\n";
    villages.push_back(vt);
    vt.cell("C3");
    vt.village("V3");
    std::clog << ".\n";
    villages.push_back(vt);
    auto vu = Village();
    vt.village("V4");
    vu = vt;
    std::clog << ".\n";
    villages.push_back(vu);
  }
  std::cout.put('\n');

  {
    auto vt = std::move(Village("C6", "P5", "D4", "S3", "L2", "V1"));
    villages.push_back(vt);
    vt = std::move(Village({ "C6", "P5", "D4", "S3", "L2", "V2", }));
    villages.push_back(vt);
    vt = std::move(Village("C6", "P5", "D4", "S3", "L2", "V3"));
    villages.push_back(vt);
    vt.village("v4");
    auto vu = Village(std::move(vt));
    villages.push_back(vu);
  }
  std::cout.put('\n');

  auto show = [](auto const & villages) {
    for (auto vc { 0ul }; auto & ville : villages) {
      std::cout << "Village"
                << std::setw(3)
                << ++vc << ": "
                << ville
                << std::endl;
    }
  };

  std::cout.put('\n');
  std::cout << std::string(80, '.')
            << std::endl;
  std::cout << std::boolalpha;
  std::clog << "?\n";
  std::cout << "[0]: " << villages[0] << '\n'
            << "[1]: " << villages[1] << '\n';
  std::clog << "?\n";
  std::cout << "[0] == [1]: "
            << (villages[0] == villages[1]) << '\n';
  std::clog << "?\n";
  std::cout << "[1] == [0]: "
            << (villages[1] == villages[0]) << '\n';
  std::clog << "?\n";
  std::cout << "[0] == [0]: "
            << (villages[0] == villages[0]) << '\n';
  std::cout.put('\n');
  std::clog << "?\n";
  std::cout << "[0] != [1]: "
            << (villages[0] != villages[1]) << '\n';
  std::clog << "?\n";
  std::cout << "[1] != [0]: "
            << (villages[1] != villages[0]) << '\n';
  std::clog << "?\n";
  std::cout << "[0] != [0]: "
            << (villages[0] != villages[0]) << '\n';
  std::cout.put('\n');
  std::clog << "?\n";
  std::cout << "[0] <  [1]: "
            << (villages[0] <  villages[1]) << '\n';
  std::clog << "?\n";
  std::cout << "[1] <  [0]: "
            << (villages[1] <  villages[0]) << '\n';
  std::clog << "?\n";
  std::cout << "[0] <  [0]: "
            << (villages[0] <  villages[0]) << '\n';
  std::cout.put('\n');
  std::clog << "?\n";
  std::cout << "[0] >  [1]: "
            << (villages[0] >  villages[1]) << '\n';
  std::clog << "?\n";
  std::cout << "[1] >  [0]: "
            << (villages[1] >  villages[0]) << '\n';
  std::clog << "?\n";
  std::cout << "[0] >  [0]: "
            << (villages[0] >  villages[0]) << '\n';
  std::cout.put('\n');
  std::clog << "?\n";
  std::cout << "[0] <= [1]: "
            << (villages[0] <= villages[1]) << '\n';
  std::clog << "?\n";
  std::cout << "[1] <= [0]: "
            << (villages[1] <= villages[0]) << '\n';
  std::clog << "?\n";
  std::cout << "[0] <= [0]: "
            << (villages[0] <= villages[0]) << '\n';
  std::cout.put('\n');
  std::clog << "?\n";
  std::cout << "[0] >= [1]: "
            << (villages[0] >= villages[1]) << '\n';
  std::clog << "?\n";
  std::cout << "[1] >= [0]: "
            << (villages[1] >= villages[0]) << '\n';
  std::clog << "?\n";
  std::cout << "[0] >= [0]: "
            << (villages[0] >= villages[0]) << '\n';
  std::cout.put('\n');
  std::cout.put('\n');

  std::cout << std::string(80, '=')
            << std::endl;
  show(villages);
  std::cout.put('\n');
  std::cout << std::string(80, '~')
            << std::endl;
  std::sort(villages.begin(), villages.end());
  show(villages);
  std::cout.put('\n');
  std::cout << std::string(80, '=')
            << std::endl;
  std::cout << std::endl;

  return 0;
}
