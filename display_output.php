<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="refresh" content="5"> <!-- Refresh every 5 seconds -->
    <title>Real-time Log Output</title>
    <style>
        *{
            font-size:18px;
        }
        body {
            font-family:serif;
            margin: 20px;
            background-color: #FFD1E3;
        }
        h1 {
            color: #333;
            text-align: center;
            font-size:34px;
        }
        pre {
            background-color: #fff;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1);
            overflow-x: auto;
            max-width: 90%;
            margin: 0 auto;
            white-space: pre-wrap; /* CSS for preformatted text to wrap */
        }
    </style>
</head>
<body>
    <h1>SeatSense</h1>
    <hr>
    <h1>Vacancy of Seats Information</h1>
    <pre>
    <?php
    $log_file = 'C:\Users\Anukrati\Documents\putty.log'; // Path to the log file

    if (file_exists($log_file)) {
        // Read the log file contents
        $log_content = file_get_contents($log_file);
        // Escape any special characters in the content
        echo htmlspecialchars($log_content);
    } else {
        echo 'Log file not found.';
    }
    ?>
    </pre>
</body>
</html>
