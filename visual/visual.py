#Clean version for now

import re
import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt
import seaborn as sns

def file_parsing(file_path):
    cnt = 0
    output_list = []
    output_links = []

    with open(file_path, 'r') as fp:
        for line in fp:
            cnt += 1
            #checks for the room name and coordinates
            if re.match('([^\s#]{1,10}) (\d+) (\d+)', line, re.MULTILINE):
                output_list.append(line.strip().split(' '))
            #checks for linking rooms
            if re.search('^\w*([-])\w*', line, re.MULTILINE):
                output_links.append(line.strip().split('-'))
            #checks for start
            if line.startswith('##start'):
                output_list.append(next(fp, '').strip().split())
            #checks for start
            if line.startswith('##end'):
                output_list.append(next(fp, '').strip().split())
    room_name = [item[0] for item in output_list]
    x_coord = [int(item[1]) for item in output_list]
    y_coord = [int(item[2]) for item in output_list]
    x_y = list(zip(x_coord, y_coord))
    links_x = [item[0] for item in output_links]
    links_y = [item[1] for item in output_links]
    links = list(zip(links_x, links_y))
    return (room_name, links, output_list, x_y)

# def graph_all():
rooms, links, room_coords, xpos_ypos = file_parsing('ex.txt')
# print(start[0].split(' '))
print("Room information: ", rooms)
print("Room information: ", room_coords)
print("X and Y position as tuple list: ", xpos_ypos)
print("Links: ", links)
G = nx.DiGraph()
# testing = ['a2a', '1', '2', 'ahs6']
G.add_edges_from(links)
# G.add_node(name = 'a2a')
# name = nx.get_node_attributes(G, 'name')

fig = plt.figure(num=None, figsize=(390, 340), dpi=80)
# fig = plt.figure()
nx.draw(G, pos=nx.random_layout(G), node_size=1200, with_labels=True, edge_color='white')
# fig.set_facecolor("#00000F")
fig.savefig("test1.png", facecolor='black')
# nx.draw_networkx(G, name)

# plt.figure()
