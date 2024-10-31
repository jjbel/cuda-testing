#pragma once

#include <chrono> // for duration

struct Stopwatch
{
    using Duration = std::chrono::duration<double>;

    std::chrono::steady_clock::time_point start{std::chrono::steady_clock::now()};

    void reset();

    [[nodiscard]] auto time() const -> Duration;

    [[nodiscard]] auto seconds() const -> double;

    [[nodiscard]] auto current_fps() -> double;
};


void Stopwatch::reset() { start = std::chrono::steady_clock::now(); }

auto Stopwatch::time() const -> Stopwatch::Duration
{
    const auto finish = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<Duration>(finish - start);
}

[[nodiscard]] auto Stopwatch::seconds() const -> double { return this->time().count(); }

[[nodiscard]] auto Stopwatch::current_fps() -> double
{
    const auto sec = seconds();
    reset();
    return 1.0 / sec;
}
