float operator "" _Kelvin(const unsigned long long temperature_kelvin)
{
    return temperature_kelvin - 273.15f;
}

float operator "" _Fahrenheit(const unsigned long long temperature_fahrenheit)
{
    return (temperature_fahrenheit - 32) / 1.8f;
}