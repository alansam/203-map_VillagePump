
#pragma once

// enable when compiler can support spaceships
//#define SPOCK_

#include <string>
#ifdef SPOCK_
#include <compare>
#endif

class Village {
public:
  Village(std::string const & cy = "",
          std::string const & pe = "",
          std::string const & dt = "",
          std::string const & sr = "",
          std::string const & cl = "",
          std::string const & ve = "") :
    country_   { cy },
    province_  { pe },
    district_  { dt },
    sector_    { sr },
    cell_      { cl },
    village_   { ve }
  {
    std::clog << "@[" << this << "]"
              << " In " << __func__
              << "(std::string const &,std::string const &,std::string const &,std::string const &std::string const &,std::string const &) - Default c'tor\n";
  }

  Village(Village const & that) :
    country_   { that.country_ },
    province_  { that.province_ },
    district_  { that.district_ },
    sector_    { that.sector_ },
    cell_      { that.cell_ },
    village_   { that.village_ }
  {
    std::clog << "@[" << this << "]"
              << " In " << __func__
              << "(Village const &) - Copy c'tor\n";
  }

  Village(Village && that) {
    std::clog << "@[" << this << "]"
              << " In " << __func__
              << "(Village &&) - Move c'tor\n";
    country_  = std::move(that.country_);
    province_ = std::move(that.province_);
    district_ = std::move(that.district_);
    sector_   = std::move(that.sector_);
    cell_     = std::move(that.cell_);
    village_  = std::move(that.village_);
  }

  ~Village() {
    std::clog << "@[" << this << "]"
              << " In "
              << __func__
              << "() - D'tor\n";
  }

  Village const & operator=(Village const & that) {
    std::clog << "@[" << this << "]"
              << "@[" << this << "]"
              << " In " << __func__
              << "(Village const &) - Copy assignment\n";
    country_  = that.country_;
    province_ = that.province_;
    district_ = that.district_;
    sector_   = that.sector_;
    cell_     = that.cell_;
    village_  = that.village_;

    return *this;
  }

  Village & operator=(Village && that) {
    std::clog << "@[" << this << "]"
              << "In " << __func__
              << "(Village &&) - Move assignment\n";
    country_  = std::move(that.country_);
    province_ = std::move(that.province_);
    district_ = std::move(that.district_);
    sector_   = std::move(that.sector_);
    cell_     = std::move(that.cell_);
    village_  = std::move(that.village_);

    return *this;
  }

/*
  bool operator<(Village const & that) const {
    std::clog << "@[" << this << "]"
              << "In " << __func__
              << "(Village const &)\n";

    auto leh = [](auto const & lh, auto const & rh) {
      auto leh = -1;
      if      (lh < rh)  { leh = -1; }
      else if (lh == rh) { leh = 0; }
      else               { leh = 1; }
      return leh;
    };

    auto ct = leh(country_, that.country_);
    auto pe = leh(province_, that.province_);
    auto dt = leh(district_, that.district_);
    auto sr = leh(sector_, that.sector_);
    auto cl = leh(cell_, that.cell_);
    auto ve = leh(village_, that.village_);

    auto lt = false;
    if      (ct < 0) { lt = true;  }  //  country
    else if (ct > 0) { lt = false; }
    else if (pe < 0) { lt = true;  }  //  province
    else if (pe > 0) { lt = false; }
    else if (dt < 0) { lt = true;  }  //  district
    else if (dt > 0) { lt = false; }
    else if (sr < 0) { lt = true;  }  //  sector
    else if (sr > 0) { lt = false; }
    else if (cl < 0) { lt = true;  }  //  cell
    else if (cl > 0) { lt = false; }
    else if (ve < 0) { lt = true;  }  //  village
    else if (ve > 0) { lt = false; }

    return lt;
  }

  bool operator>(Village const & that) const {
    std::clog << "@[" << this << "]"
              << "In " << __func__
              << "(Village const &)\n";

    auto leh = [](auto const & lh, auto const & rh) {
      auto leh = -1;
      if      (lh < rh)  { leh = -1; }
      else if (lh == rh) { leh = 0; }
      else               { leh = 1; }
      return leh;
    };

    auto ct = leh(country_, that.country_);
    auto pe = leh(province_, that.province_);
    auto dt = leh(district_, that.district_);
    auto sr = leh(sector_, that.sector_);
    auto cl = leh(cell_, that.cell_);
    auto ve = leh(village_, that.village_);

    auto gt = false;
    if      (ct > 0) { gt = true;  }  //  country
    else if (ct < 0) { gt = false; }
    else if (pe > 0) { gt = true;  }  //  province
    else if (pe < 0) { gt = false; }
    else if (dt > 0) { gt = true;  }  //  district
    else if (dt < 0) { gt = false; }
    else if (sr > 0) { gt = true;  }  //  sector
    else if (sr < 0) { gt = false; }
    else if (cl > 0) { gt = true;  }  //  cell
    else if (cl < 0) { gt = false; }
    else if (ve > 0) { gt = true;  }  //  village
    else if (ve < 0) { gt = false; }

    return gt;
  }

  bool operator>=(Village const & that) const {
    std::clog << "@[" << this << "]"
              << "In " << __func__
              << "(Village const &)\n";
    return !(*this < that);
  }

  bool operator<=(Village const & that) const {
    std::clog << "@[" << this << "]"
              << "In " << __func__
              << "(Village const &)\n";
    return !(*this > that);
  }

  bool operator==(Village const & that) const {
    std::clog << "@[" << this << "]"
              << "In " << __func__
              << "(Village const &)\n";
    return (!(*this < that) && !(*this > that));
  }

  bool operator!=(Village const & that) const {
    std::clog << "@[" << this << "]"
              << "In " << __func__
              << "(Village const &)\n";
    return !(*this == that);
  }
 */

#ifdef SPOCK_
  auto operator<=>(Village const &)
  const = default;
#else
  bool operator==(Village const & that)
  const noexcept {
    std::clog << "@[" << this << "]"
              << "In " << __func__
              << "(Village const &)\n";
    return country_  == that.country_
        && province_ == that.province_
        && district_ == that.district_
        && sector_   == that.sector_
        && cell_     == that.cell_
        && village_  == that.village_;
  }

  bool operator!=(Village const & that)
  const noexcept {
    std::clog << "@[" << this << "]"
              << "In " << __func__
              << "(Village const &)\n";
    return !(*this == that);
  }

  bool operator<(Village const & that)
  const {
    std::clog << "@[" << this << "]"
              << "In " << __func__
              << "(Village const &)\n";
    return  (country_  <  that.country_)

    ||     ((country_  == that.country_)
    &&      (province_ <  that.province_))

    ||     ((country_  == that.country_)
    &&      (province_ == that.province_)
    &&      (district_ <  that.district_))

    ||     ((country_  == that.country_)
    &&      (province_ == that.province_)
    &&      (district_ == that.district_)
    &&      (sector_   <  that.sector_))

    ||     ((country_  == that.country_)
    &&      (province_ == that.province_)
    &&      (district_ == that.district_)
    &&      (sector_   == that.sector_)
    &&      (cell_     <  that.cell_))

    ||     ((country_  == that.country_)
    &&      (province_ == that.province_)
    &&      (district_ == that.district_)
    &&      (sector_   == that.sector_)
    &&      (cell_     == that.cell_)
    &&      (village_  <  that.village_))
    ;
  }

  bool operator>(Village const & that)
  const {
    std::clog << "@[" << this << "]"
              << "In " << __func__
              << "(Village const &)\n";
    return that < *this;
  }

  bool operator<=(Village const & that)
  const {
    std::clog << "@[" << this << "]"
              << "In " << __func__
              << "(Village const &)\n";
    return !(that < *this);
  }

  bool operator>=(Village const & that)
  const {
    std::clog << "@[" << this << "]"
              << "In " << __func__
              << "(Village const &)\n";
    return !(*this < that);
  }
#endif  // SPOCK_

  //  getters & setters
  std::string const & village(void)
  const noexcept {
    return village_;
  }
  std::string & village(std::string const & vl)
  noexcept {
    return (village_ = vl);
  }

  std::string const & cell(void)
  const noexcept {
    return cell_;
  }
  std::string & cell(std::string const & cl)
  noexcept {
    return (cell_ = cl);
  }

  std::string const & sector(void)
  const noexcept {
    return sector_;
  }
  std::string & sector(std::string const & sr)
  noexcept {
    return (sector_ = sr);
  }

  std::string const & district(void)
  const noexcept {
    return district_;
  }
  std::string & district(std::string & dt)
  noexcept {
    return (district_ = dt);
  }

  std::string const & province(void)
  const noexcept {
    return sector_;
  }
  std::string & province(std::string const & pe)
  noexcept {
    return (province_ = pe);
  }

  std::string const & country(void)
  const noexcept {
    return country_;
  }
  std::string & country(std::string const & cy)
  noexcept {
    return (country_ = cy);
  }

  friend
  std::ostream & operator<<(std::ostream & os,
                            Village const & that) {
    os << that.country_  << ", "
       << that.province_ << ", "
       << that.district_ << ", "
       << that.sector_   << ", "
       << that.cell_     << ", "
       << that.village_;

    return os;
  }

private:
  std::string village_;
  std::string cell_;
  std::string sector_;
  std::string district_;  
  std::string province_;
  std::string country_;
};
