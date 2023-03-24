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
- <endL>: A custom delimiter to indicate the end of the command. In this case, the delimiter is the sequence /g/u/y.

Responses from the server follow the format:

    <STATUS><sp><CODE><sp><MESSAGE><endL>

- <STATUS>: The status of the response, usually a brief keyword or numeric code to indicate the success or failure of the command (e.g., OK, ERROR).
- <sp>: A space used to separate the response elements.
- <CODE>: A code corresponding to the message type or the specific message being sent.
- <MESSAGE>: The actual message content or information being sent as a response.
- <endL>: The custom delimiter to indicate the end of the response, which is the sequence /g/u/y in this case.

7. Error Handling

Errors in the MyTeams protocol are handled by returning an error code (e.g., 84) and an error message on the error output. Clients should handle these errors appropriately.

8. Security

While password authentication is not required for this project, developers should implement basic security measures, such as ensuring that only logged-in users can access certain features and preventing unauthorized access to teams, channels, and threads.
