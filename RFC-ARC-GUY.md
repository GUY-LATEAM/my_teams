MyTeams Protocol Specification
RFC: ARC-GUY

1. Introduction

This document describes the MyTeams protocol, which is designed to facilitate communication and collaboration within teams through a server-client architecture. The protocol supports a range of features, including user authentication, team and channel management, thread and comment creation, and personal messaging.

2. Terminology

- Server: The central component that manages the communication between clients and maintains the application state.
- Client: An endpoint that connects to the server to interact with the MyTeams application.
- Team: A group of users collaborating on a specific project or topic.
- Channel: A subcategory within a team that focuses on a particular aspect of the team's project or topic.
- Thread: A conversation within a channel, consisting of an initial post and additional comments.
- Comment: A message in response to a thread's initial post or another comment.

3. Architecture

The MyTeams protocol is built on a client-server architecture using TCP sockets for communication. The server maintains the application state, including users, teams, channels, threads, and comments. Clients connect to the server to send commands and receive updates.

4. Data Model

The data model consists of the following structures:

- User: Contains user-related information, such as UUID, username, and connection status.
- Team: Contains team-related information, such as UUID, name, and description.
- Channel: nelContains chan-related information, such as UUID, name, and description.
- Thread: Contains thread-related information, such as UUID, title, and initial message.
- Comment: Contains comment-related information, such as UUID and message body.

5. Commands

The MyTeams protocol supports the following commands:

- /help: show help
- /login ["username"]: set the user_name used by client
- /logout: disconnect the client from the server
- /users: get the list of all users that exist on the domain
- /user ["user_uuid"]: get information about a user
- /send ["user_uuid"] ["message_body"]: send a message to a user
- /messages ["user_uuid"]: list all messages exchanged with a user
- /subscribe ["team_uuid"]: subscribe to the event of a team and its subdirectories (enable reception of all events from a team)
- /subscribed? ["team_uuid"]: list all subscribed teams or list all users subscribed to a team
- /unsubscribe ["team_uuid"]: unsubscribe from a team
- /use? ["team_uuid"]? ["channel_uuid"]? ["thread_uuid"]: use specify a context team/channel/thread
- /create: based on what is being used create the subresource (see below)
- /list: based on what is being used list all the subresources (see below)
- /info: based on what is being used list the current (see below)

6. Command and Response Format

Commands sent by the client follow the format:

    <CMD><sp><args><endL>

- <CMD>: The command keyword (e.g., /login, /users, etc.).
- <sp>: A space separating the command keyword and its arguments.
- <args>: The command arguments, if any, enclosed in double quotes and separated by spaces (e.g., "username", "team_uuid").
- <endL>: A custom delimiter to indicate the end of the command. In this case, the delimiter is the sequence \g\u\y.

<args>: The arguments for the command, if necessary, enclosed in double quotes and separated by spaces (e.g., "username", "team_uuid"). The specific data to include for each command is described below.
Data to include for each command:

    /login -> "username" - The username the client will use.
    /user -> "user_uuid" - The UUID of the user to get information about.
    /send -> "user_uuid", "message_body" - The UUID of the user to send the message to and the message content.
    /messages -> "user_uuid" - The UUID of the user with whom to list exchanged messages.
    /subscribe -> "team_uuid" - The UUID of the team to subscribe to.
    /subscribed? -> "team_uuid" - The UUID of the team to list subscribed users for.
    /unsubscribe -> "team_uuid" - The UUID of the team to unsubscribe from.
    /use -> "team_uuid:channel_uuid:thread_uuid" - The UUIDs of the team, channel, and thread to use to determine the context.
    /create -> "team_uuid:channel_uuid:thread_uuid" - The context in which to create the resource (team, channel, or thread).
    /list -> "team_uuid:channel_uuid:thread_uuid" - The context for which to list all resources (teams, channels, or threads).
    /info -> "team_uuid:channel_uuid:thread_uuid" - The context for which to display information (team, channel, or thread).
    The context for the /use, /create, /list, and /info commands is a string in the format "team_uuid:channel_uuid:thread_uuid". The server must use these UUIDs to determine the context in which the command should be executed.


Responses from the server follow the format:

    <STATUS><sp><CODE><sp><MESSAGE><endL>

- <STATUS>: The status of the response,indicate the success or failure of the command (OK, ERROR).
- <sp>: A space used to separate the response elements.
- <CODE>: A code corresponding to the message type or the specific message being sent.
- <MESSAGE>: The actual message content or information being sent as a response.
- <endL>: The custom delimiter to indicate the end of the response, which is the sequence \g\u\y.in this case.

<CODE> : 

Response codes are three-digit numeric codes used to indicate the outcome of a command. Response codes are grouped into five classes, based on the first digit of the code:

    1xx (Informational): The request was received, and the server continues to process it.
    2xx (Successful): The request was successfully received, understood, and accepted.
    3xx (Redirection): Additional action needs to be taken to complete the request.
    4xx (Client Error): The request contains bad syntax or cannot be fulfilled by the server.
    5xx (Server Error): The server failed to fulfill an apparently valid request.

Here are some example response codes for your MyTeams protocol:

    200 OK: The command was successfully processed.
    201 Created: The resource was successfully created (e.g., a team, channel, or thread).
    204 No Content: The command was successfully processed, but there is no data to return (e.g., upon logout).
    400 Bad Request: The received command is malformed or invalid.
    401 Unauthorized: The client needs to authenticate before performing this action.
    403 Forbidden: The client does not have the necessary permissions to perform this action.
    404 Not Found: The requested resource was not found (e.g., a user, team, channel, or thread).
    500 Internal Server Error: An error occurred on the server side while processing the command.

7. Error Handling

Errors in the MyTeams protocol are handled by returning an error code (e.g., 84) and an error message on the error output. Clients should handle these errors appropriately.

8. Security

While password authentication is not required for this project, developers should implement basic security measures, such as ensuring that only logged-in users can access certain features and preventing unauthorized access to teams, channels, and threads.

