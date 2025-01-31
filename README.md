![version-alpha](https://img.shields.io/badge/version-alpha-orange)
![license](https://img.shields.io/badge/license-MIT-brightgreen)
![C99](https://img.shields.io/badge/C-99-blue)

# Dummy

**Dummy** is a command-line tool designed to help you manage and execute test suites for your project. It allows you to initialize projects, create or remove test suites and individual tests, build and run the tests, manage configurations, and clean up the generated files. Below is a detailed guide on how to use the various commands available in Dummy.

## Install

Run this command in your terminal
```code
git clone https://github.com/dukesaturn/dummy_test
``` 
In your work directory copy the package. 
Then, run the following command
```
chmod +x dummy
```
Now, the script is executable.
Run this command for initializing your project

```
./dummy --init <name>
```

## Usage
```
`dummy <action> [options]`
```
## Actions and Options

### 1. Initialize the project
To initialize a project, use the `-i` or `--init` action. You can optionally specify a project name.
```
`dummy --init [project_name]`
```
- **project_name** (optional): Name of the project you are initializing.

**Example:**
```
`dummy --init MyProject`
```
### 2. Create a suite or test
To create a new test suite or test, use the `-m` or `--make` action. You must specify the type (`suite` or `test`) and the name.
```
`dummy --make <type> <name>`
```
- **type**: Can be either `suite` or `test`.
- **name**: Name of the suite or test to create. For tests, use the format `suite_name:test_name`.

#### Options for creation:
- **suite**: Create a new test suite.
```
  `dummy --make suite <suite_name>`
```
- **test**: Create a new test inside a specific suite.
```
  `dummy --make test <suite_name>:<test_name>`
```
**Examples:**
- Create a new suite named `login_tests`:
```
  `dummy --make suite login_tests`
```
- Create a new test named `login_success` inside the `login_tests` suite:
```
  `dummy --make test login_tests:login_success`
```
### 3. Remove a suite or test
To remove an existing suite or test, use the `-r` or `--remove` action. You must specify the type and name.
```
`dummy --remove <type> <name>`
```
- **type**: Can be either `suite` or `test`.
- **name**: Name of the suite or test to remove. For tests, use the format `suite_name:test_name`.

#### Options for removal:
- **suite**: Remove a test suite.
```
  `dummy --remove suite <suite_name>`
```
- **test**: Remove a test from a specific suite.
```
  `dummy --remove test <suite_name>:<test_name>`
```
**Examples:**
- Remove a test suite named `login_tests`:
```
  `dummy --remove suite login_tests`
```
- Remove a test named `login_success` from the `login_tests` suite:
```
  `dummy --remove test login_tests:login_success`
```
### 4. Build the project
To build the project or a specific test suite, use the `-b` or `--build` action. You can build all suites or a specific suite.
```
`dummy --build <mode> [name]`
```
- **mode**: Can be `all` to build the entire project or `suite` to build a specific suite.
- **name** (optional): Name of the suite to build if you are building a specific suite.

#### Options for building:
- **all**: Build the entire project.
```
  `dummy --build all`
```
- **suite**: Build a specific test suite.
```
  `dummy --build suite <suite_name>`
```
**Examples:**
- Build the entire project:
```
  `dummy --build all`
```
- Build the `login_tests` suite:
```
  `dummy --build suite login_tests`
```
### 5. List suites or tests
To list available test suites or tests, use the `-l` or `--list` action. You can list all tests or tests within a specific suite.
```
`dummy --list <type>`
```
- **type**: Can be `all` to list all tests or `suite` to list tests in a specific suite.

#### Options for listing:
- **all**: List all tests in the project.
```
  `dummy --list all`
```
- **suite**: List tests within a specific test suite.
```
  `dummy --list suite <suite_name>`
```
**Examples:**
- List all tests in the project:
```
  `dummy --list all`
```
- List all tests within the `login_tests` suite:
```
  `dummy --list suite login_tests`
```
### 6. Run tests
To execute the tests, use the `-R` or `--run` action.
```
`dummy --run`
```
**Example:**
```
`dummy --run`
```
### 7. Update configuration
To set or update a configuration field in `config.json`, use the `-c` or `--config` action. You need to specify the field and its new value.
```
`dummy --config <field> <value>`
```
- **field**: Name of the configuration field to update.
- **value**: New value for the configuration field.

**Example:**
```
`dummy --config timeout 300`
```
### 8. Clean up generated files
To clean up generated files and directories, use the `-C` or `--clean` action.
```
`dummy --clean`
```
**Example:**
```
`dummy --clean`
```
### 9. Show help message
To show the help message, use the `--help` option.
```
`dummy --help`
```
```
