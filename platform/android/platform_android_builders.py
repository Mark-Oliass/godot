"""Functions used to generate source files during build time"""

import subprocess
import sys


def generate_apk(target, source, env):
    gradle_process = []

    if sys.platform.startswith("win"):
        gradle_process = [
            "cmd",
            "/c",
            "gradlew.bat",
        ]
    else:
        gradle_process = ["./gradlew"]

    gradle_process += [
        "generateGodotEditor" if env["target"] == "editor" else "generateGodotTemplates",
        "--quiet",
    ]

    if env["debug_symbols"]:
        gradle_process += ["-PdoNotStrip=true"]

    subprocess.run(
        gradle_process,
        cwd="platform/android/java",
    )
