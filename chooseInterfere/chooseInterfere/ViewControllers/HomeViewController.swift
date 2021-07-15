//
//  HomeViewController.swift
//  chooseInterfere
//
//  Created by 최강훈 on 2021/07/13.
//

import UIKit
import Firebase
import FirebaseDatabase
import CodableFirebase

class HomeViewController: UIViewController {

    
    @IBOutlet weak var tableView: UITableView!
    var posts: [Post] = []
    
    override func viewDidLoad() {
        super.viewDidLoad()

        self.tableView.dataSource = self
        self.tableView.delegate = self
        
        var ref: DatabaseReference!
        ref = Database.database().reference()
        ref.child("posts").getData { error, snapshot in
            if snapshot.exists() {
                guard let value = snapshot.value else {return}
                do {
                    let posts = try FirebaseDecoder().decode(
                        [Post].self, from: value)
                    print(posts)
                    self.posts = posts
                    DispatchQueue.main.async {
                        self.tableView.reloadData()
                    }
                } catch let err {
                    print (err)
                }
            }
        }
        
    }
    
    

}

extension HomeViewController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.posts.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        guard let cell = self.tableView.dequeueReusableCell(withIdentifier: HomeContentsTableViewCell.staticReuseIdentifier, for: indexPath) as? HomeContentsTableViewCell
        else {return UITableViewCell()}
        
        if self.posts.count == 0 { return UITableViewCell() }
        let post = self.posts[indexPath.row]
        
        cell.titleLabel?.text = post.title
        cell.userNickNameDateViewCountLabel?.text =
            "\(post.userNickName) | \(post.createDate) | \(post.viewCount)"
        cell.descriptionLabel?.text = post.description
        if post.images == nil {
            cell.imageContainerView.isHidden = true
        } else {
            cell.imageCountLabel?.text = "1 / \(String(describing: post.images?.count))"
        }
        
        cell.isLikeImageView?.image = post.isLike == true ?
            UIImage(systemName: "suit.heart.fill") :
            UIImage(systemName: "suit.heart")
        cell.likeCountLabel?.text = String(post.likeCount)
        cell.commentCountLabel?.text = "댓글(\(String(post.commentCount)))"
        
        
        return cell
    }
    
    
}
