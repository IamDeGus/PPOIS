#pragma once


class IUnitConverter
{
public:

    virtual double toMetric() const;
    virtual double toImperial() const;

    virtual ~IUnitConverter() = default;
};
