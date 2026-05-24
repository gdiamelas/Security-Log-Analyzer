# Security Log Analyzer

A lightweight command-line utility written in C designed to parse server log files, isolate unauthorized access attempts, and generate automated security status reports.

This project demonstrates foundational concepts in low-level file I/O, memory management, and rule-based threat detection.

## Technical Capabilities

* **Stream-Based File I/O:** Efficiently reads and processes standard text-based log files line-by-line without overloading memory buffers.
* **Pattern Matching:** Utilizes C standard library functions (`strstr`) for sequential string parsing and signature detection.
* **Automated Threat Assessment:** Evaluates systemic risk by triggering security warnings (e.g., potential Brute-Force attacks) when failed login thresholds are breached.

## Functional Overview

The application monitors a designated target file named `server_logs.txt`. During execution, it sequentially scans each entry for the `FAILED` keyword. Upon completion, the program aggregates the telemetry data and outputs a comprehensive analysis report directly to the standard output.

## AI-Assisted Development
This project was developed using an AI-assisted workflow and a Human-AI pair programming approach, leveraging Large Language Models (LLMs) for code optimization and structural refinement.

### Target Output Structure

```text
=== SECURITY LOG ANALYZER ===
Scanning for suspicious activities...

[ALERT] Suspicious Activity Found: 2026-05-23 10:15:01 User 'root' - FAILED LOGIN...
[ALERT] Suspicious Activity Found: 2026-05-23 10:15:05 User 'root' - FAILED LOGIN...

=== ANALYSIS REPORT ===
Total Failed Login Attempts Detected: 4
Security Status: WARNING (Potential Brute-Force Attack)
