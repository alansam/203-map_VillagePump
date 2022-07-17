
#pragma once

// enable when compiler can support spaceships
//#define SPOCK_

#include <string>
#ifdef SPOCK_
#include <compare>
#endif

using namespace std::literals::string_literals;

class Village {
public:
  Village(std::string const & cy = ""s,
          std::string const & pe = ""s,
          std::string const & dt = ""s,
          std::string const & sr = ""s,
          std::string const & cl = ""s,
          std::string const & ve = ""s) :
    country_   { cy },
    province_  { pe },
    district_  { dt },
    sector_    { sr },
    cell_      { cl },
    village_   { ve }
  {
    std::clog << "@["s << std::setw(18) << this << "]"s
              << " In "s << __func__
              << "(std::string const &,std::string const &,std::string const &,std::string const &std::string const &,std::string const &) - Default c'tor\n"s;
  }

  Village(Village const & that) :
    country_   { that.country_ },
    province_  { that.province_ },
    district_  { that.district_ },
    sector_    { that.sector_ },
    cell_      { that.cell_ },
    village_   { that.village_ }
  {
    std::clog << "@["s << std::setw(18)  << this << "]"s
              << " In "s << __func__
              << "(Village const &) - Copy c'tor\n"s;
  }

  Village(Village && that) {
    std::clog << "@["s << std::setw(18)  << this << "]"s
              << " In "s << __func__
              << "(Village &&) - Move c'tor\n"s;
    country_  = std::move(that.country_);
    province_ = std::move(that.province_);
    district_ = std::move(that.district_);
    sector_   = std::move(that.sector_);
    cell_     = std::move(that.cell_);
    village_  = std::move(that.village_);
  }

  ~Village() {
    std::clog << "@["s << std::setw(18)  << this << "]"s
              << " In "s
              << __func__
              << "() - D'tor\n"s;
  }

  Village const & operator=(Village const & that) {
    std::clog << "@["s << std::setw(18)  << this << "]"s
              << " In "s << __func__
              << "(Village const &) - Copy assignment\n"s;
    country_  = that.country_;
    province_ = that.province_;
    district_ = that.district_;
    sector_   = that.sector_;
    cell_     = that.cell_;
    village_  = that.village_;

    return *this;
  }

  Village & operator=(Village && that) {
    std::clog << "@["s << std::setw(18)  << this << "]"s
              << " In "s << __func__
              << "(Village &&) - Move assignment\n"s;
    country_  = std::move(that.country_);
    province_ = std::move(that.province_);
    district_ = std::move(that.district_);
    sector_   = std::move(that.sector_);
    cell_     = std::move(that.cell_);
    village_  = std::move(that.village_);

    return *this;
  }

#ifdef SPOCK_
  auto operator<=>(Village const &)
  const = default;
#else
  bool operator==(Village const & that)
  const noexcept {
    std::clog << "@["s << std::setw(18)  << this << "]"s
              << " In "s << __func__
              << "(Village const &)\n"s;
    return country_  == that.country_
        && province_ == that.province_
        && district_ == that.district_
        && sector_   == that.sector_
        && cell_     == that.cell_
        && village_  == that.village_;
  }

  bool operator!=(Village const & that)
  const noexcept {
    std::clog << "@["s << std::setw(18)  << this << "]"s
              << " In "s << __func__
              << "(Village const &)\n"s;
    return !(*this == that);
  }

  bool operator<(Village const & that)
  const {
    std::clog << "@["s << std::setw(18)  << this << "]"s
              << " In "s << __func__
              << "(Village const &)\n"s;
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
    std::clog << "@["s << std::setw(18)  << this << "]"s
              << " In "s << __func__
              << "(Village const &)\n"s;
    return that < *this;
  }

  bool operator<=(Village const & that)
  const {
    std::clog << "@["s << std::setw(18)  << this << "]"s
              << " In "s << __func__
              << "(Village const &)\n"s;
    return !(that < *this);
  }

  bool operator>=(Village const & that)
  const {
    std::clog << "@["s << std::setw(18)  << this << "]"s
              << " In "s << __func__
              << "(Village const &)\n"s;
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
    os << that.country_  << ", "s
       << that.province_ << ", "s
       << that.district_ << ", "s
       << that.sector_   << ", "s
       << that.cell_     << ", "s
       << that.village_;

    return os;
  }

private:
  std::string country_;
  std::string province_;
  std::string district_;  
  std::string sector_;
  std::string cell_;
  std::string village_;
};
