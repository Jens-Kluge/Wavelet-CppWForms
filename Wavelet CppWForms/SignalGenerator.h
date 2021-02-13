#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

#ifndef _SIGGEN_H
#define _SIGGEN_H

/* same behaviour as Math::Sign
* x > 0: return 1
* x = 0: return 0
* x < 0: return -1
*/
int sign(double v);

typedef enum enSignalType
{
    Sawtooth,
    Sine,
    Square,
    Triangle
} SignalType;

public ref class SignalGenerator
{

private:
    SignalType signalType = enSignalType::Sine;
    /// <summary>
    /// Signal Type.
    /// </summary>
public:
    property SignalType sigType {
        SignalType get() { return signalType; }
        void set(SignalType value) { signalType = value; }
    }

private:
    float frequency = 1.0f;
    /// <summary>
    /// Signal Frequency.
    /// </summary>
public:
    property float Frequency
    {
        float get() { return frequency; }
        void set(float value) { frequency = value; }
    }

private:
    float phase = 0.0f;
    /// <summary>
    /// Signal Phase.
    /// </summary>
public:
    property float Phase
    {
        float get() { return phase; }
        void set(float value) { phase = value; }
    }

private:
    float amplitude = 1.0f;
    /// <summary>
    /// Signal Amplitude.
    /// </summary>
public:
    property float Amplitude
    {
        float get() { return amplitude; }
        void set(float value) { amplitude = value; }
    }

private:
    float offset = 0.0f;
    /// <summary>
    /// Signal Offset.
    /// </summary>
public:
    property float Offset
    {
        float get() { return offset; }
        void set(float value) { offset = value; }
    }

private:
    float invert = 1; // Yes=-1, No=1
    /// <summary>
    /// Signal Inverted?
    /// </summary>
public:
    property bool Invert
    {
        bool get() { return invert == -1; }
        void set(bool value) { invert = value ? -1 : 1; }
    }

        /// <summary>
        /// Time the signal generator was started
        /// </summary>
private:
        long startTime = System::Diagnostics::Stopwatch::GetTimestamp();

        /// <summary>
        /// Ticks per second on this CPU
        /// </summary>
private:
    long ticksPerSecond = System::Diagnostics::Stopwatch::Frequency;

 
public:
    SignalGenerator(SignalType initialSignalType)
    {
            signalType = initialSignalType;
    }

public:
    SignalGenerator() { }

public:
    float GetValue(float time)
    {
            float value = 0.0f;
            float t = frequency * time + phase;
            switch (signalType)
            { // http://en.wikipedia.org/wiki/Waveform
            case enSignalType::Sine: // sin( 2 * pi * t )
                value = (float)sin(2.0f * M_PI * t);
                break;
            case enSignalType::Square: // sign( sin( 2 * pi * t ) )
                value = sign(sin(2.0f * M_PI * t));
                break;
            case enSignalType::Triangle:
                // 2 * abs( t - 2 * floor( t / 2 ) - 1 ) - 1
                value = 1.0f - 4.0f * (float)abs(round(t - 0.25f) - (t - 0.25f));
                break;
            case enSignalType::Sawtooth:
                // 2 * ( t/a - floor( t/a + 1/2 ) )
                value = 2.0f * (t - (float)floor(t + 0.5f));
                break;
            }

            return(invert * amplitude * value + offset);
        }

     public:
        float GetValue()
        {
            float time = (float)(System::Diagnostics::Stopwatch::GetTimestamp() - startTime)
                / ticksPerSecond;
            return GetValue(time);
        }

    public:
        void Reset()
        {
            startTime = System::Diagnostics::Stopwatch::GetTimestamp();
        }
  
};
#endif //_SIGGEN_H


