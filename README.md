# BusTrainReservationSystem

Simple console-based C++ Bus and Train reservation system. Includes user/admin management, schedule viewing, ticket booking, cancellation, and basic file-backed persistence.

## Contents
- Source: `*.cpp`, `*.h`
- Project file: `BusTrainReservationSystem.cbp`
- Sample data: `schedule.txt`

## Files to include in the repository
- Source code: `Admin.cpp`, `Admin.h`, `User.cpp`, `User.h`, `Ticket.cpp`, `Ticket.h`, `Schedule.cpp`, `Schedule.h`, `FileManager.cpp`, `FileManager.h`, `main.cpp`
- Project configuration: `BusTrainReservationSystem.cbp`, `CppProperties.json`
- Sample/reference data: `schedule.txt`

## Files ignored (do not push)
- Build artifacts and folders: `bin/`, `obj/`, `Debug/`, `Release/`
- Compiled and linker files: `*.exe`, `*.obj`, `*.ilk`, `*.pdb`
- Runtime data: `tickets.txt`, `users.txt` (these are generated at runtime)
- Editor/OS files: `.vs/`, `*.user`, `Thumbs.db`, `*.DS_Store`

## Build (Windows - MSVC `cl.exe`)
Open a Developer Command Prompt or use your IDE. Example command (run from project folder):

```powershell
cl.exe /Zi /EHsc /nologo /Fe:BusTrainReservationSystem.exe main.cpp Admin.cpp FileManager.cpp Schedule.cpp Ticket.cpp User.cpp
```

Or open `BusTrainReservationSystem.cbp` in Code::Blocks and build from there.

## Run
After building, run:

```powershell
.\BusTrainReservationSystem.exe
```

Ensure `schedule.txt` is in the same folder so schedules load correctly.
