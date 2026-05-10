# Lily
A C++ game engine built for learning — following the architecture of a real engine from first principles.

**Stack:** C++17 · OpenGL · GLFW · Dear ImGui · spdlog · glm · Windows only

## Building

Requires Visual Studio 2022 and Premake5.

```powershell
# Generate project files
premake5 vs2022

# Build (or open Lily.sln in Visual Studio)
msbuild Lily.sln /p:Configuration=Debug /p:Platform=x64
```

Output: `bin/Debug-windows-x86_64/Sandbox/Sandbox.exe`

## Project Structure

| Project | Role |
|---------|------|
| `Lily` | Core engine — compiled as a DLL |
| `Sandbox` | Test application — links against Lily.dll |

See `ARCHITECTURE.md` for a full explanation of how the systems fit together and why they're designed the way they are.
See `ROADMAP.md` for the development plan phase by phase.
