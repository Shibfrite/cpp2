#include "ScalarConverter.hpp"
#include "support.hpp"

std::string toChar(t_data data) {
    long val = -1;
    switch (data.type) {
        case CHAR:   val = static_cast<long>(data.value.c); break;
        case INT:    val = static_cast<long>(data.value.i); break;
        case FLOAT:  val = static_cast<long>(data.value.f); break;
        case DOUBLE: val = static_cast<long>(data.value.d); break;
        default: break;
    }
    if (val < 0 || val > 127)
        return ERR_MSG_IMPOSSIBLE;
    if (!isPrintable(static_cast<char>(val)))
        return ERR_MSG_UNPRINTABLE;
    return '\'' + std::string(1, static_cast<char>(val)) + '\'';
}

std::string toInt(t_data data) {
    long val = -1;
    switch (data.type) {
        case CHAR:   val = static_cast<long>(data.value.c); break;
        case INT:    val = static_cast<long>(data.value.i); break;
        case FLOAT:  val = static_cast<long>(data.value.f); break;
        case DOUBLE: val = static_cast<long>(data.value.d); break;
        default: break;
    }
    if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
        return ERR_MSG_IMPOSSIBLE;
    return to_str(static_cast<int>(val));
}

std::string toFloat(t_data data) {
    float       val = -1;
    std::string result;

    switch (data.type) {
        case CHAR:   val = static_cast<float>(data.value.c); break;
        case INT:    val = static_cast<float>(data.value.i); break;
        case FLOAT:  val = data.value.f; break;
        case DOUBLE: val = static_cast<float>(data.value.d); break;
        default: break;
    }
    if (data.type == DOUBLE && std::isinf(val) && !std::isinf(data.value.d))
      return ERR_MSG_IMPOSSIBLE;
    result = to_str(val);
    if (!std::isnan(val) && !std::isinf(val) && result.find('.') == std::string::npos)
      result += ".0";
    return result + 'f';
}

std::string toDouble(t_data data) {
    double      val = -1;
    std::string result;

    switch (data.type) {
        case CHAR:   val = static_cast<double>(data.value.c); break;
        case INT:    val = static_cast<double>(data.value.i); break;
        case FLOAT:  val = static_cast<double>(data.value.f); break;
        case DOUBLE: val = data.value.d; break;
        default: break;
    }
    result = to_str(val);
    if (!std::isnan(val) && !std::isinf(val) && result.find('.') == std::string::npos && result.find('e') == std::string::npos)
      result += ".0";
    return result;
}
