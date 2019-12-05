#include <clingo.hh>
#include <string>

using namespace Clingo;

class ExampleApp : public Application {
public:
    ExampleApp() : program_{"base"} { }

    char const *program_name() const noexcept override {
        return "example";
    }

    char const *version() const noexcept override {
        return "1.0.0";
    }

    void register_options(ClingoOptions &app) override {
        app.add("Example", "program", "Override the default program part to ground", [this](char const *value){ return parse_program_(value); });
    }

    void main(Control &ctl, StringSpan files) override {
        // load files into the control object
        for (auto &file : files) { ctl.load(file); }
        // if no files are given read from stdin
        if (files.empty()) { ctl.load("-"); }

        // ground & solve
        ctl.ground({{ program_.c_str(), {} }});
        ctl.solve(LiteralSpan{}, nullptr, false, false).get();
    }

private:
    bool parse_program_(char const *value) {
        program_ = value;
        return true;
    }

private:
    std::string program_;
};

int main(int argc, char const **argv) {
    ExampleApp app;
    return clingo_main(app, {argv+1, static_cast<size_t>(argc)-1});
}
