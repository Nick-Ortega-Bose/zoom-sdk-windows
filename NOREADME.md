## Setting up the coding environment
### VS Code
Download here: https://code.visualstudio.com/

### Visual studio build tools
Current repository is configured for 2019

During download for build tools 2017 or 2019, you must configure individual components and select both ATL and MFC support. You will also need to add the build tools binaries to the PATH:

- C:\Program Files (x86)\Microsoft Visual Studio\201X\BuildTools\MSBuild\Current\Bin\

2019 - https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=BuildTools&rel=16

2017 - https://my.visualstudio.com/Downloads?q=visual%20studio%202017&wt.mc_id=o~msft~vscom~older-downloads (add "build tools" to the search)

2015 - https://my.visualstudio.com/Downloads?q=visual%20studio%202015&wt.mc_id=o~msft~vscom~older-downloads (add "remote tools" to the search)

### Nuget
Only necessary if not downloaded with 2017 or 2019

The folder you put it in needs to be added to the PATH

https://www.nuget.org/downloads - it's in the leftmost column

What you download is not an installer - it is the executable needed to be on your path

### VS Code Extensions
In vs code, add extensions for your coding environment

Click on the four squares button

Search for the "C/C++" extension from Microsoft

(this is not necessary for the build, but it is nice to have)

Extension settings are configured correctly by default

This repository also has a json to customize the setting: .vscode\c_cpp_properties.json

## Running the demo build
### From command line
**Assuming you are in the "zoomsdk" folder (modify path if necessary)**

msbuild /P:Configuration=Release /P:Platform=x86 demo\sdk_demo_v2\sdk_demo_v2.vcxproj

### Using VSCode tasks
From the top menu bar, go to "Terminal>Run Build Task" OR press Ctrl+Shift+B

Choose "demo" if prompted

### In either case
Output should be in the "bin" folder: bin\sdk_demo_v2.exe

At this point, you only need the build folder to run the executable

## Further development
The "template" folder has a useful "template.vcxproj"

- Additional binary libraries (compiled for VS 2017+) should have their own folders

- Add their necessary .h files to the vcxproj as below

- Add include paths to the <ItemDefinitionGroup> -> <ClCompile> block

- Add paths to libraries to the <ItemDefinitionGroup> -> <Link> block

- Add .cpp files to the "ItemGroup" -> "ClCompile" section

- Add .h files to the "ItemGroup" -> "ClInclude" sections

- Replace all references to template / temp

Add new build settings to the .vscode\tasks.json

Debug settings can be added to the <ItemGroup Label="ProjectConfigurations"> block,
but extra settings will be necessary (some tags will need a "Conditional" attribute)

## Legal Notice
https://visualstudio.microsoft.com/license-terms/mt644918/

## If you're starting from scratch
### Zoom sdk
Get current version through github
- **Must be through github!**
Revert back to last verified commit

### Build Settings
**From command line:**

'''msbuild /P:Configuration=Release /P:Platform=x86 path\to\sdk_demo_v2_2017.vcxproj'''

**In tasks.json:**

Look at tasks.json in this repo for template

Replace ms build command with yours
