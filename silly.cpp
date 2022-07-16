
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifdef SILLY
int main_loops(int argc, char ** argv) {
  std::string search_ville;
  std::string map[1][2][1][1][2][5];
  for (int country = 0; country < 1; country++) {
    for (int province = 0; province < 2; province++) {
      for (int district = 0; district < 1; district++) {
        for (int sector = 0; sector < 1; sector++) {
          for (int cell = 0; cell < 2; cell++) {
            for (int village = 0; village < 5; village++) {
              std::cout << "enter the village of country" << country << " province " << province << " district " << district << " sector  " << sector << " cell " << cell << " village " << village << std::endl;
              std::cin >> map[country][province][district][sector][cell][village];
            }
          }
        }
      }
    }
  }
  std::cout << "Enter the village : " << std::endl;
  std::cin >> search_ville;
  for (int country = 0; country < 1; country++) {
    for (int province = 0; province < 2; province++) {
      for (int district = 0; district < 1; district++) {
        for (int sector = 0; sector < 1; sector++) {
          for (int cell = 0; cell < 2; cell++) {
            for(int village = 0; village < 5; village++) {
              if (search_ville == map[country][province][district][sector][cell][village]) {
                std::cout << map[country][province][district][sector][cell][village] << std::endl;
              }
              else {
                std::cerr << "no such available for " << search_ville << std::endl;
              }
            }
          }
        }
      }
    }
  }

  return 0;
}
#endif /* SILLY */
