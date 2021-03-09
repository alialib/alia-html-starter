#include <alia/html.hpp>

using namespace alia;

// Here's the 'Interactive Hello' example from the docs.
void
greeting_ui(html::context ctx, duplex<std::string> name)
{
    html::p(ctx, "What's your name?");

    // Allow the user to input their name.
    html::input(ctx, name);

    // If we have a name, greet the user.
    alia_if(name != "")
    {
        html::p(ctx, "Hello, " + name + "!");
    }
    alia_end
}

// Here's the main UI function for our app.
void
app_ui(html::context ctx)
{
    // Set the document title.
    document_title(ctx, "alia/HTML Starter");

    // Root our content in the HTML body at the element with the ID
    // "app-content".
    placeholder_root(ctx, "app-content", [&] {
        h1(ctx, "Hello, World!").classes("mt-5 mb-3");

        p(ctx, "Welcome to alia/HTML!");

        auto name = get_state(ctx, "");
        greeting_ui(ctx, name);
    });
}

// main() just initializes alia/HTML and hooks up our app UI.
int
main()
{
    static html::system the_sys;
    initialize(the_sys, app_ui);
};
