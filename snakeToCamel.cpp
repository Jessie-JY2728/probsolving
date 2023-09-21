// The classic question of converting a string of snake casing to camel casing
// Working solution in cpp
// Eg. this_is_an_example -> thisIsAnExample

string snake_to_camel(string s) {
    char* arr = &s[0];
    char* tok;
    stringstream ss;
    tok = strtok(arr, "_ ");
    while (tok != NULL) {
        tok[0] += ('A' - 'a');
        ss << tok;
        tok = strtok(NULL, "_ ");
    }
    string out = ss.str();
    out[0] += ('a' - 'A');
    return out;
}

int main() {
    string str = "hello_world_this_time";
    cout << snake_to_camel(str);
    return 0;
}
