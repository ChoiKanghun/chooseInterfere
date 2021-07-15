//
//  Post.swift
//  chooseInterfere
//
//  Created by 최강훈 on 2021/07/14.
//

import Foundation

struct Posts: Codable {
    let posts: [Post]
}

struct Post: Codable {
    let createDate: Date
    let modifyDate: Date
    let title: String
    let description: String
    let images: [String: Image]?
    let isLike: Bool
    let userNickName: String
    let viewCount: Int
    let commentCount: Int
    let comments: [String: Comment]?
    let voteOptions: [VoteOption]?
    let likeCount: Int
    
    init(createDate: Date,
         modifyDate: Date,
         title: String,
         description: String,
         images: [String: Image]?,
         isLike: Bool,
         userNickName: String,
         viewCount: Int,
         commentCount: Int,
         comments: [String: Comment]?,
         voteOptions: [VoteOption]?,
         likeCount: Int
    ) {
        self.createDate = createDate
        self.modifyDate = modifyDate
        self.title = title
        self.description = description
        self.images = images
        self.isLike = isLike
        self.userNickName = userNickName
        self.viewCount = viewCount
        self.commentCount = commentCount
        self.comments = comments
        self.voteOptions = voteOptions
        self.likeCount = likeCount
    }
}

struct Comment: Codable {
    let createDate: Date
    let modifyDate: Date
    let description: String
    let isLike: Bool
    let likeCount: Int
    let userNickName: String
}

struct Image: Codable {
    let imageSource: String
}

struct VoteOption: Codable {
    let option: String
    let optionCount: Int
}

