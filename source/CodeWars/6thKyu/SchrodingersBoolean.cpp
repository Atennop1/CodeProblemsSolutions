class SchrodingersBoolean
{
public:
    bool operator==(bool boolean)
    {
        return true;
    }

    bool operator==(SchrodingersBoolean boolean)
    {
        return true;
    }
};

SchrodingersBoolean omnibool;
